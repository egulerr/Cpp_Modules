#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45){
	this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref)
	: AForm(ref)
{
	this->target = ref.target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	static int i = 0;
	if (!getSign())
	{
		if (this->getGradeToExecute() >= executor.getGrade()) {
			if (i % 2 == 0) {
				cout << this->target << " has been robotomized." << endl;
				i++;
			} else {
				cout << "Robotomy failed." << endl;
				i++;
			}
		}
	}
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ref) {
	(void)ref;
	return (*this);
}