#include "PmergeMe.hpp"

int main(int ac, char **av) {
    PmergeMe pm;

    if (ac >= 3 && pm.checkArgs(av)) {
        
    }
    else
        std::cout << "invalid error" << std::endl;
}