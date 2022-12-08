#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main( void ) {
	Intern	someRandomIntern;
	Form*	rrf;
	Form*	xxd;
	Form*	llm;
	Form*	empty;

	rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "hi");
	xxd = someRandomIntern.makeForm("PresidentialPardonForm", "hello");
	llm = someRandomIntern.makeForm("RobotomyRequestForm", "thanks");
	empty = someRandomIntern.makeForm("NO", "you");
}
