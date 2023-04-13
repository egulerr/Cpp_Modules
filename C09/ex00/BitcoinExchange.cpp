#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() {}

Bitcoin::~Bitcoin() {}

Bitcoin::Bitcoin(const Bitcoin &ref) { *this = ref; }

Bitcoin &Bitcoin::operator=(const Bitcoin &ref){
    for (std::map<std::string, double>::const_iterator it = ref.btc_map.begin(); it != ref.btc_map.end(); ++it)
        this->btc_map.insert(*it);
    return (*this);
}

int Bitcoin::checkIsOpen(char **av) const {
    std::ifstream file(av[1]);
    if (file.good())
        return (1);
    else
        return (0);
}

void Bitcoin::readFile(char *av) {
    std::ifstream file(av);
    std::string row;
    std::string *rows = nullptr;
    int size = 0;

    while (std::getline(file, row)){
        std::string *temp = new std::string[size + 1];
        for (int i = 0; i < size; i++)
            temp[i] = rows[i];
        delete[] rows;
        rows = temp;
        rows[size] = row;
        size++;          
    }
    checkDates(rows, size);
    checkValue(rows, size);
    fillData(rows, size);  
    for (int i = 0; i < size; i++)
        std::cout << rows[i] << std::endl;
    delete[] rows; 
}

void Bitcoin::checkDates(std::string *rows, int size) {
    int maxDateCount = size;
    std::string dates[maxDateCount];
    int years[100];
    int months[100];
    int days[100];
    int dateCount = 0;

    for (int i = 0; i < size; i++) {
        std::string row = rows[i];
        size_t found = row.find("|");
        std::string date;
        if (found != std::string::npos)
            date = row.substr(0, found);
        else
            date = row;
        dates[dateCount] = date;
        dateCount++;
    }

    for (int i = 0; i < dateCount; i++){
        std::string date = dates[i];
        std::stringstream ss(date);
      
        std::string part;
        int partCount = 0;
        bool isValid = true;

        while (getline(ss, part, '-')) {
            partCount++;
            int partInt = std::stoi(part);
            if (partCount == 1) {
                if (partInt < 2009 || partInt > 2022) {
                    isValid = false;
                    break;
                }
                years[i] = partInt;
            }
            else if (partCount == 2) {
                if (partInt < 1 || partInt > 12) {
                    isValid = false;
                    break;
                }
                months[i] = partInt;
            }
            else if (partCount == 3) {
                int maxDays = 31;
                if (months[i] == 2) {
                    maxDays = 28;
                    if (years[i] % 4 == 0 && (years[i] % 100 != 0 || years[i] % 400 == 0))
                        maxDays = 29;
                }
                else if (months[i] == 4 || months[i] == 6 || months[i] == 9 || months[i] == 11)
                    maxDays = 30;
                if (partInt < 1 || partInt > maxDays) {
                    isValid = false;
                    break;
                }
                days[i] = partInt;
            }
        }
        if (!isValid)
            rows[i] = "Error: bad input => " + date;
    }
}

void Bitcoin::checkValue(std::string* rows, int size) {
    for (int i = 0; i < size; i++) {
        if (rows[i].find("Error") != std::string::npos)
            continue;
        std::string row = rows[i];
        size_t found = row.find('|');
        if (found != std::string::npos) {
            std::string value = row.substr(found + 1);
            try {
                double num = std::stod(value);
                if (num < 0)
                    rows[i] = "Error: not a positive number.";
                else if (num > 1000)
                    rows[i] = "Error: too large a number.";
            }
            catch (const std::invalid_argument& e) {
                rows[i] = "Error: not a valid number.";
            }
            catch (const std::out_of_range& e) {
                rows[i] = "Error: too large a number.";
            }
        }
        else
            rows[i] = "Error: '|' character not found.";
    }
}


void Bitcoin::fillData(std::string *rows, int size) {
    std::ifstream file("data.csv");
    std::string row;

    std::getline(file, row);
    while (std::getline(file, row)) {
        size_t found = row.find(',');
        std::string date = row.substr(0, found);
        std::string value = row.substr(found + 1);
        double num = std::stod(value);
        btc_map.insert(std::pair<std::string, double>(date, num));
    }

    int precision = 5;

    for (int i = 0; i < size; i++) {
        if (rows[i].find("Error") != std::string::npos)
            continue;
        size_t found = rows[i].find('|');
        std::string date = rows[i].substr(0, found);
        date = date.substr(0, date.size() - 1);
        std::string value = rows[i].substr(found + 1);
        std::map<std::string, double>::iterator it = btc_map.find(date);
        if (it != btc_map.end()) {
            double result = it->second * std::stod(value);
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(precision) << result;
            std::string result_str = oss.str();
            while (result_str.back() == '0')
                result_str.pop_back();
            if (result_str.back() == '.')
                result_str.pop_back();
            rows[i] = date + " => " + value + " = " + result_str;
        }
        else
        {
            it = btc_map.lower_bound(date);
            if (it != btc_map.begin()) {
                it--;
                double result = it->second * std::stod(value);
                std::ostringstream oss;
                oss << std::fixed << std::setprecision(precision) << result;
                std::string result_str = oss.str();
                while (result_str.back() == '0')
                    result_str.pop_back();
                if (result_str.back() == '.')
                    result_str.pop_back();
                rows[i] = it->first + " => " + value + " = " + result_str;
            }
        }
    }
}
