#include <iostream>
#include <stack>

class RPN {
    public:
        std::stack<int> rpn_stack;
        int operands[100];
        int operandsCount;
        char operators[100];

        RPN();
        ~RPN();
        RPN(const RPN &ref);

        char **seperateSpace(char *av);
        int checkArguments(char *av);
        int checkInput(char **input);
        int executeOperation(char operatr, int num, int num2);
        void initializeRPN();
};