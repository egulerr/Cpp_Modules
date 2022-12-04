#include <iostream>
#include <iomanip>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	system("clear");
	std::cout << "STRING:               "<< &str << "\n";
	std::cout << "POINTER TO STRING:    " << stringPTR << "\n";
	std::cout << "REFERENCE TO STRING:  " << &stringREF << "\n\n";

	std::cout << "VALUE OF STRING:      " << str << "\n";
	std::cout << "POINTED:              " << *stringPTR << "\n";
	std::cout << "REFERENCED:           " << stringREF << "\n";
}