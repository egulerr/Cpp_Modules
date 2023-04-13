#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
#include <iomanip>

class Bitcoin {
    public:
        std::map<std::string, double> btc_map;

        Bitcoin();
        ~Bitcoin();
        Bitcoin(const Bitcoin &ref);
        Bitcoin& operator = (const Bitcoin &ref);

        int checkIsOpen(char *av) const;
        void readFile(char *av);

        void checkDates(std::string *rows, int size);
        void checkValue(std::string *rows, int size);
        void fillData(std::string *rows, int size);
};