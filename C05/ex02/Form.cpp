#include "Form.hpp"

AForm::AForm() : name("default"), sign(1), gradeToSign(10), gradeToExecute(5){}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute)
	: name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw (gradeTooLowException());
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw(gradeTooHighException());
}

const char* AForm::gradeTooHighException::what() const throw(){
	return ("Too high grade");
}
const char* AForm::gradeTooLowException::what() const throw(){
	return ("To low grade");
}

AForm::AForm(const AForm &ref)
	: name(ref.name), gradeToSign(ref.gradeToSign)
	,gradeToExecute(ref.gradeToExecute)
{
	*this = ref;
}

AForm &AForm::operator=(const AForm &ref)
{
	this->sign = ref.sign;
	return (*this);
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->gradeToSign) {
		this->sign = true;
		cout << bureaucrat.getName() << " has signed " << this->name << endl;
	} else{
		cout << bureaucrat.getName() << " can't sign " << this->name << endl;
		throw AForm::gradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream &out, AForm &in){
	out << "Form " << in.getName()
		<< ", status: " << (in.getSign() ? "signed" : "not signed")
		<< ", sign grade: " <<in.getGradeToSign()
		<< ", execute grade: " << in.getGradeToExecute();
	return (out);
}

AForm::~AForm() {}
