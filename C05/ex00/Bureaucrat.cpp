# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _grade(grade), _name(name){
	if (grade > 150)
		throw(gradeTooLowException());
	else if (grade < 1)
		throw(gradeTooHighException());
	std::cout << "default const called" << std::endl;
}

const char* Bureaucrat::gradeTooHighException::what() const throw() {
	return "To high grade";
}

const char* Bureaucrat::gradeTooLowException::what() const throw() {
	return "To low grade";
}

Bureaucrat::~Bureaucrat() {
	std::cout << "destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat &in){
	out << in.getName() << ", bureaucrat grade " << in.getGrade();
	return out;
}