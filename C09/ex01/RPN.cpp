#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &ref)
{
	*this = ref;
}

char **RPN::seperateSpace(char *av)
{
	const char delim[] = " ";
	char *token = std::strtok(av, delim);

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

	return args;
}

int RPN::checkInput(char **input)
{
	int operandIndex = 0;
	int operatorIndex = 0;

	for (int i = 0; input[i] != nullptr; i++)
	{
		if (std::isdigit(input[i][0]))
		{
			this->operands[operandIndex] = std::atoi(input[i]);
			operandIndex++;
		}
		else if (input[i][0] == '*' || input[i][0] == '/' || input[i][0] == '+' || input[i][0] == '-')
		{
			this->operators[operatorIndex] = input[i][0];
			operatorIndex++;
		}
		else
		{
			std::cerr << "Invalid character: " << input[i][0] << std::endl;
			return 0;
		}
	}
	if (operandIndex - operatorIndex != 1)
	{
		std::cerr << "Too many operands or operators in expression" << std::endl;
		return 0;
	}
	this->operandsCount = operandIndex;
	this->operators[operatorIndex] = '\0';
	return 1;
}

int RPN::checkArguments(char *av)
{
	char **args = seperateSpace(av);
	if (checkInput(args))
	{

		return 1;
	}
	else
		return 0;
}

int RPN::executeOperation(char operatr, int num, int num2) {
	int result = 0;
	switch (operatr) {
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


void RPN::initializeRPN() {
	int opCount = 0;
	for (int i = 0; i < this->operandsCount; i++) {
		this->rpn_stack.push(this->operands[i]);
		if (rpn_stack.size() == 2) {
			int num2 = rpn_stack.top();
			rpn_stack.pop();
			int num = rpn_stack.top();
			rpn_stack.pop();
			int result = executeOperation(this->operators[opCount], num, num2);
			rpn_stack.push(result);
			opCount++;
		}
	}
	std::cout << rpn_stack.top() << std::endl;
}
