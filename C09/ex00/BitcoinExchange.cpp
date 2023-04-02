#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() {}

Bitcoin::~Bitcoin() {}

Bitcoin::Bitcoin(const Bitcoin &ref) { *this = ref; }

Bitcoin &Bitcoin::operator=(const Bitcoin &ref) {
    for (std::map<std::string, double>::const_iterator it = ref.btc_map.begin(); it != ref.btc_map.end(); ++it) {
        this->btc_map.insert(*it);
    }
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
    std::vector<std::string> tokens;
    std::vector<std::string> rows;


    std::getline(file, row); // ilk satırı oku ve atla
    while (std::getline(file, row)) {
        rows.push_back(row);
    }
    checkDates(rows);
    checkValue(rows);
    fillData(rows);
    std::cout << "önce row:" << std::endl;  
    for (std::vector<std::string>::iterator it = rows.begin(); it != rows.end(); ++it) {
        std::cout << *it << std::endl;
    } 
}

std::vector<std::string> &Bitcoin::checkDates(std::vector<std::string> &rows) {
    std::vector<int> years;
    std::vector<int> months;
    std::vector<int> days;
    std::vector<std::string> dates;

    for (unsigned int i = 0; i < rows.size(); i++){
        std::string row = rows[i];
        size_t found = row.find("|");
        std::string date = row.substr(0, found);
        if (found != std::string::npos) {
            std::string date = row.substr(0, found);
            dates.push_back(date);
        }
        else
            dates.push_back(date);
    }
    
    for (unsigned long i = 0; i < dates.size(); i++) {
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
                years.push_back(partInt);
            } else if (partCount == 2) {
                if (partInt < 1 || partInt > 12) {
                    isValid = false;
                    break;
                }
                months.push_back(partInt);
            } else if (partCount == 3) {
                int maxDays = 31;
                if (months.back() == 2) {
                    maxDays = 28;
                    if (years.back() % 4 == 0 && (years.back() % 100 != 0 || years.back() % 400 == 0)) {
                        maxDays = 29;
                    }
                } else if (months.back() == 4 || months.back() == 6 || months.back() == 9 || months.back() == 11) {
                    maxDays = 30;
                }
                if (partInt < 1 || partInt > maxDays) {
                    isValid = false;
                    break;
                }
                days.push_back(partInt);
            }
        }

        if (!isValid) {
            rows[i] = "Error: bad input => " + date;
        }
    }

    return rows;
}
std::vector<std::string> &Bitcoin::checkValue(std::vector<std::string> &rows) {
    std::vector<std::string> valueStrs;
    for (unsigned int i = 0; i < rows.size(); i++) {
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
            } catch (const std::invalid_argument &e) {
                rows[i] = "Error: not a valid number.";
            } catch (const std::out_of_range &e) {
                rows[i] = "Error: too large a number.";
            }
            valueStrs.push_back(value);
        } else {
            rows[i] = "Error: '|' character not found.";
        }
    }
    return rows;
}

void Bitcoin::fillData(std::vector<std::string> &rows) {
    std::ifstream file("data.csv");
    std::string row;
    std::map<std::string, double> database;

    // Read data from the file into the map
    std::getline(file, row); // skip the first line
    while (std::getline(file, row)) {
        size_t found = row.find(',');
        std::string date = row.substr(0, found);
        std::string value = row.substr(found + 1);
        double num = std::stod(value);
        database.insert(std::pair<std::string, double>(date, num));
    }

    for (size_t i = 0; i < rows.size(); i++) {
        if (rows[i].find("Error") != std::string::npos)
            continue;
        size_t found = rows[i].find('|');
        std::string date = rows[i].substr(0, found);
        date = date.substr(0, date.size()-1);
        std::string value = rows[i].substr(found + 1);
        std::map<std::string, double>::iterator it = database.find(date);
        if (it != database.end()) {
            double result = it->second * std::stod(value);
            rows[i] = date + " => " + value + " = " + std::to_string(result);
        } else {
            it = database.lower_bound(date);
            if (it != database.begin()) {
                it--;
                double result = it->second * std::stod(value);
                rows[i] = it->first + " => " + value + " = " + std::to_string(result);
            }
        }
    }
}









/* std::istringstream iss(rows);
        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        } */