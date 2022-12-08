#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(string target) : Form("ShrubberyCreationForm", 145, 137){
	this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref)
	: Form(ref)
{
	this->target = ref.target;
}

const char* ShrubberyCreationForm::checkSigned::what() const throw(){
	return "Cant Signed";
}

const char* ShrubberyCreationForm::checkGrade::what() const throw(){
	return "Level is not enough for execute.";
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!getSign()) {
		if (this->getGradeToExecute() >= executor.getGrade()) {
			string name;
			name = target;
			name += "_shrubbery";
			std::fstream dir;
			dir.open(name, std::ios::out);
			dir << "               ,@@@@@@@," << endl
				<< "       ,,,.   ,@@@@@@/@@,  .oo8888o." << endl
				<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << endl
				<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << endl
				<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << endl
				<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << endl
				<< "   `&%\\ ` /%&'    |.|        \\ '|8'" << endl
				<< "       |o|        | |         | |" << endl
				<< "       |.|        | |         | |" << endl
				<< "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << endl;
		} else{
			throw (checkGrade());
		}
	}
	else {
		throw (checkSigned());
	}
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref) {
	(void)ref;
	return *this;
}