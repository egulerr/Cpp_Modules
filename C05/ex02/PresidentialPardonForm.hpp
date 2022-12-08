#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"
using std::cout;
using std::endl;
using std::string;

class PresidentialPardonForm: public Form{
private:
	string target;
	PresidentialPardonForm();
public:
	PresidentialPardonForm(string target);
	PresidentialPardonForm(const PresidentialPardonForm &ref);
	PresidentialPardonForm& operator = (const PresidentialPardonForm &ref);
	~PresidentialPardonForm();
	void execute(const Bureaucrat &executor) const;
};

#endif
