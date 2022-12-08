#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"
using std::cout;
using std::string;
using std::endl;

class RobotomyRequestForm: public Form{
private:
	string target;
	RobotomyRequestForm();
public:
	RobotomyRequestForm(string target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &ref);
	RobotomyRequestForm& operator = (const RobotomyRequestForm &ref);
	void execute(const Bureaucrat &executor) const;
};
#endif
