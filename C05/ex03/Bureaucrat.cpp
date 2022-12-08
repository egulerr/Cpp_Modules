#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
	if (grade > 150)
		throw(gradeTooLowException());
	else if (grade < 1)
		throw(gradeTooHighException());
}

const char* Bureaucrat::gradeTooHighException::what() const throw() {
	return "To high grade";
}

const char* Bureaucrat::gradeTooLowException::what() const throw() {
	return "To low grade";
}

Bureaucrat::~Bureaucrat() {}

std::ostream& operator<<(std::ostream &out, Bureaucrat &in){
	out << in.getName() << ", bureaucrat grade " << in.getGrade();
	return out;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) : _name(ref._name){
	cout << "Copy constructor called." << endl;
	*this = ref;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &ref) {
	this->_grade = ref._grade;
	return (*this);
}

Bureaucrat::Bureaucrat() :_name("default"), _grade(150){}

void Bureaucrat::decrement(int amount) {
	if (_grade + amount > 150)
		throw gradeTooLowException();
	_grade += amount;
}

void Bureaucrat::increment(int amount) {
	if (_grade - amount < 1)
		throw gradeTooHighException();
	_grade -= amount;
}

void Bureaucrat::signForm(Form &form) {
	form.beSigned(*this);
}

const char *Bureaucrat::execTooLowException::what() const throw() {
	return ("Not enough to execute");
}

void Bureaucrat::executeForm(const Form &form)
{
	try {
		if (!form.getSign()) {
			if (form.getGradeToExecute() >= getGrade())
				cout << getName() << " executed " << form.getName() << endl;
			else
				throw (execTooLowException());
		}
	} catch (const std::exception &ex){
		cout << ex.what() << " for \"" << form.getName() << "\""<<endl;
	}
}
