#include "BitcoinExchange.hpp"
 
int main(int ac, char **av) {
    Bitcoin btc;

    if (ac > 1){
        for (size_t i = 1; av[i]; i++){
            if (ac >= 2 && btc.checkIsOpen(av[i])) 
                btc.readFile(av[i]);
            else
                std::cout << "Error: could not open file." << std::endl;
        }
    }
    else
        std::cout << "Error: Argument count is not correct." << std::endl;
}