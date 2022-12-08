#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){
}

int Intern::giveANumber(std::string name) {
	if (name == "ShrubberyCreationForm")
		return (1);
	else if (name == "RobotomyRequestForm")
		return (2);
	else if (name == "PresidentialPardonForm")
		return (3);
	else
		return (4);
}

Form* Intern::makeForm(std::string name, std::string target) {
	Form *form;
	int num = giveANumber(name);

	switch (num) {
		case 1:
			form = new ShrubberyCreationForm(target);
			cout << "Intern creates " << form->getName() << endl;
			break;
		case 2:
			form = new RobotomyRequestForm(target);
			cout << "Intern creates " << form->getName() << endl;
			break;
		case 3:
			form = new PresidentialPardonForm(target);
			cout << "Intern creates " << form->getName() << endl;
			break;
		default:
			form = NULL;
			cout << "Incorrect input" << endl;
			break;
	}
	return (form);
}
