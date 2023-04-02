#include "BitcoinExchange.hpp"
 
int main(int ac, char **av) {
    Bitcoin btc;

    if (ac == 2 && btc.checkIsOpen(av)) {
        btc.readFile(av[1]);
    }
    else
        std::cout << "Error: could not open file." << std::endl;
}