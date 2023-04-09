#include <iostream>
#include <stack>
#include <string>
#include <sstream>

class RPN {
    public:
        std::stack<int> rpn_stack;
        int operandsCount;

        RPN();
        ~RPN();
        RPN(const RPN &ref);
        RPN& operator=(const RPN &ref);
        char **seperateSpace(char *av);
        int checkArguments(char *av);
        int checkInput(char **input);
        int executeOperation(char operatr, int num, int num2);
        void initializeRPN(char *av);
        char *trimSpaces(char *av);
        void ft_delete(char **av);
};