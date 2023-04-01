#include <iostream>
#include <map>

class Bitcoin {
    public:
        std::map<std::string, double> btc_map;

        Bitcoin();
        ~Bitcoin();
        Bitcoin(const Bitcoin &ref);
        Bitcoin& operator = (const Bitcoin &ref);
};