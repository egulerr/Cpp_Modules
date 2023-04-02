#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>

class Bitcoin {
    public:
        std::map<std::string, double> btc_map;

        Bitcoin();
        ~Bitcoin();
        Bitcoin(const Bitcoin &ref);
        Bitcoin& operator = (const Bitcoin &ref);

        int checkIsOpen(char **av) const;
        void readFile(char *av);

        std::vector<std::string> &checkDates(std::vector<std::string> &rows);
        std::vector<std::string> &checkValue(std::vector<std::string> &rows);
        void fillData(std::vector<std::string> &rows);
};