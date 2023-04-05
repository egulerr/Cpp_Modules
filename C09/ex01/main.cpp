#include <iostream>
#include <stack>
#include "RPN.hpp"

int main(int ac, char **av) {
    RPN rpn;

    if (ac == 2 && rpn.checkArguments(av[1])) {
        rpn.initializeRPN();
    }
    else
        std::cout << "error" << std::endl;
}
