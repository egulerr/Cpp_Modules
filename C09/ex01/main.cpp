#include "RPN.hpp"

int main(int ac, char **av) {
    RPN rpn;

    if (ac == 2 && rpn.checkArguments(av[1])) {
        rpn.initializeRPN(av[1]);
    }
    else
        std::cout << "Error" << std::endl;
}
