#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &ref) { *this = ref; }

RPN& RPN::operator=(const RPN &ref) {
    std::stack<int> temp = ref.rpn_stack;
    while(!temp.empty()) {
        rpn_stack.push(temp.top());
        temp.pop();
    }
    return (*this);
}

char **RPN::seperateSpace(char *av)
{
	const char delim[] = " ";
	char *str = new char[strlen(av)];
	std::strcpy(str, av);
	char *token = std::strtok(str, delim);

	int argIndex = 0;
	char **args = new char *[100];

	args[argIndex] = new char[std::strlen(token) + 1];
	std::strcpy(args[argIndex++], token);

	while ((token = std::strtok(nullptr, delim)) != nullptr)
	{
		args[argIndex] = new char[std::strlen(token) + 1];
		std::strcpy(args[argIndex++], token);
	}
	args[argIndex] = nullptr;
	delete [] str;
	return args;
}

int RPN::checkInput(char **input)
{
    int operandIndex = 0;
    int operatorIndex = 0;

    for (int i = 0; input[i] != nullptr; i++)
    {
        if (std::isdigit(input[i][0])) {
            if (std::atoi(input[i]) >= 0 && std::atoi(input[i]) <= 9)
                operandIndex++;
            else {
                std::cerr << "Invalid operand: " << input[i] << std::endl;
                return 0;
            }
        }
        else if (input[i][0] == '*' || input[i][0] == '/' || input[i][0] == '+' || input[i][0] == '-')
            operatorIndex++;
        else {
            std::cerr << "Invalid character: " << input[i][0] << std::endl;
            return 0;
        }
    }
    if (operandIndex - operatorIndex != 1) {
        std::cerr << "Too many operands or operators in expression" << std::endl;
        return 0;
    }
    return 1;
}


int RPN::checkArguments(char *av)
{
	char **args = seperateSpace(av);
	if (checkInput(args)) {
		ft_delete(args);
		return 1;
	}
	else
		return 0;
}

int RPN::executeOperation(char operatr, int num, int num2)
{
	int result = 0;
	switch (operatr)
	{
	case '+':
		result = num + num2;
		break;
	case '-':
		result = num - num2;
		break;
	case '*':
		result = num * num2;
		break;
	case '/':
		result = num / num2;
		break;
	default:
		break;
	}
	return (result);
}

char *RPN::trimSpaces(char *av) {
	int len = strlen(av);
	char *str = new char[len + 1]; 
	int j = 0;
	for (int i = 0; i < len; i++) {
		if (av[i] != ' ') {
			str[j] = av[i];
			j++;
		}
	}
	str[j] = '\0';
	return (str);
}

void RPN::initializeRPN(char *av) {
	char *str = trimSpaces(av);
	bool error = false;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			rpn_stack.push(str[i] - '0');
		} else {
			if (rpn_stack.size() >= 2) {
				int num2 = rpn_stack.top();
				rpn_stack.pop();
				int num1 = rpn_stack.top();
				rpn_stack.pop();
				int res = executeOperation(str[i], num1, num2);
 				rpn_stack.push(res);
			}
			else {
				std::cout << "RPN format is not correct!" << std::endl;
				error = true;
				break;
			}
		}
	}
	if (error != true)
		std::cout << rpn_stack.top() << std::endl;
	delete[] str; 
}

void RPN::ft_delete(char **args) {
	for (int i = 0; args[i] != nullptr; i++) 
    	delete [] args[i];
	delete [] args;
}