#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"
#include <fstream>
using std::cout;
using std::endl;
using std::string;

class ShrubberyCreationForm: public Form{
private:
	string target;
	ShrubberyCreationForm(){};
public:
	ShrubberyCreationForm(string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &ref);
	ShrubberyCreationForm& operator = (const ShrubberyCreationForm &ref);
	~ShrubberyCreationForm();
	void execute(const Bureaucrat &executor) const;
	struct checkSigned : public std::exception{
		const char * what() const throw();
	};
	struct checkGrade : public std::exception{
		const char * what() const throw();
	};
};

#endif
