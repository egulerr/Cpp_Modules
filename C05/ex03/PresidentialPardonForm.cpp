#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: Form("PresidentialPardonForm", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref)
	: Form(ref)
{
	this->target = ref.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref) {
	(void)ref;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!getSign())
	{
		if (this->getGradeToExecute() >= executor.getGrade()){
			cout << this->target << " has been pardoned by Zaphod Beeblebrox." << endl;
		}
	}
}

PresidentialPardonForm::~PresidentialPardonForm() {}