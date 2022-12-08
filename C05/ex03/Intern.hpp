#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
using std::string;
using std::cout;
using std::endl;

class Intern{
private:
public:
	Intern();
	~Intern();
	Intern(const Intern &ref);
	Intern& operator = (const Intern &ref);
	Form* makeForm(string name, string target);
	int	giveANumber(string name);
};

#endif
