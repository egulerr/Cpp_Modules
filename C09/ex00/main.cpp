#include "BitcoinExchange.hpp"
 
int main()
{
    Bitcoin b1;

    b1.btc_map.insert(std::pair<std::string, double>("iki", 2));
    Bitcoin btc2(b1);
    std::cout << btc2.btc_map.find("iki")->second << std::endl;
}