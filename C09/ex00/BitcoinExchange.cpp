#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() {
    std::cout << "default" << std::endl;
}

Bitcoin::~Bitcoin() {
    std::cout << "destructor" << std::endl;
}

Bitcoin::Bitcoin(const Bitcoin &ref) {
    std::cout << "copy" << std::endl;
    *this = ref;
}

Bitcoin& Bitcoin::operator=(const Bitcoin &ref) {
    std::cout << "operator" << std::endl;

    this->btc_map = ref.btc_map;
    return (*this);
}