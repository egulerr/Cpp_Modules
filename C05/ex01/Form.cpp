#include "Form.hpp"

Form::Form() : name("default"), sign(1), gradeToSign(10), gradeToExecute(5){
	cout << "Default constructor called." << endl;
}

Form::Form(const std::string name, int gradeToSign)
	: name(name), gradeToSign(gradeToSign), gradeToExecute(0)
{
	if (gradeToSign > 150)
		throw (gradeTooLowException());
	else if (gradeToSign < 1)
		throw(gradeTooHighException());
	cout << "2 parameter constructor called." << endl;
}
const char* Form::gradeTooHighException::what() const throw(){
	return ("Too high grade");
}
const char* Form::gradeTooLowException::what() const throw(){
	return ("To low grade");
}

Form::Form(const Form &ref)
	: name(ref.name), gradeToSign(ref.gradeToSign)
	,gradeToExecute(ref.gradeToExecute)
{
	cout << "Copy constructor called." << endl;
	*this = ref;
}

Form &Form::operator=(const Form &ref)
{
	cout << "Operator overloading called." << endl;
	this->sign = ref.sign;
	return (*this);
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->gradeToSign) {
		this->sign = true;
		cout << bureaucrat.getName() << " has signed " << this->name << endl;
	} else{
		cout << bureaucrat.getName() << " can't sign " << this->name << endl;
		cout << *this << endl;
		throw Form::gradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream &out, Form &in){
	out << "Form " << in.getName()
		<< ", status: " << (in.getSign() ? "signed" : "not signed")
		<< ", sign grade: " <<in.getGradeToSign()
		<< ", execute grade: " << in.getGradeToExecute();
	return (out);
}

Form::~Form() {
	cout << "Destructor called." << endl;
}
