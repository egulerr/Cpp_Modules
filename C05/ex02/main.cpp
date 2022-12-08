#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void ) {
	//--------------------Shrubbery Objects----------------------
	try {
		Bureaucrat eyup = Bureaucrat("eyup", 120);
		ShrubberyCreationForm shrub = ShrubberyCreationForm("Eyup");
		shrub.execute(eyup);
		eyup.executeForm(shrub);
	} catch (std::exception &ex) {
		cout << ex.what() << endl;
	}
	try {
		Bureaucrat mert = Bureaucrat("mert", 143);
		ShrubberyCreationForm şurup = ShrubberyCreationForm("Mert");
		şurup.execute(mert);
	} catch (std::exception &ex) {
		cout << ex.what() << endl;
	}
	//----------------------Robot Objects-----------------------
	{
		{
			Bureaucrat hakan = Bureaucrat("hakan", 44);
			RobotomyRequestForm robot = RobotomyRequestForm("Hakan");
			robot.execute(hakan);
			hakan.executeForm(robot);
		}
		{
			Bureaucrat melih = Bureaucrat("melih", 25);
			RobotomyRequestForm robot = RobotomyRequestForm("Melih");
			robot.execute(melih);
		}
		{
			Bureaucrat salih = Bureaucrat("salih", 35);
			RobotomyRequestForm robot = RobotomyRequestForm("Salih");
			robot.execute(salih);
		}
		{
			Bureaucrat adem = Bureaucrat("adem", 40);
			RobotomyRequestForm robot = RobotomyRequestForm("Adem");
			robot.execute(adem);
		}
	}
	//---------------------President Objects------------------------
	{
		Bureaucrat ebrar = Bureaucrat("ebrar", 6);
		PresidentialPardonForm pres = PresidentialPardonForm("Ebrar");
		pres.execute(ebrar);
		ebrar.executeForm(pres);
	}
}
