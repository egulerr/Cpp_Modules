#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

using std::endl;
using std::cout;
using std::string;

class Bureaucrat;

class Form{
	private:
		const string	name;
		bool			sign;
		const int		gradeToSign;
		const int 		gradeToExecute;
	public:
		Form();
		Form(const string name, int gradeToSign);
		Form(const Form &ref);
		Form& operator = (const Form &ref);
		~Form();
		const string getName(){return (name);}
		bool getSign(){return (sign);}
		int getGradeToSign(){return (gradeToSign);}
		int getGradeToExecute(){return (gradeToExecute);}
		struct gradeTooHighException: public std::exception{
			const char * what() const throw();
		};
		struct gradeTooLowException: public std::exception{
			const char * what() const throw();
		};
		void beSigned(Bureaucrat &bureaucrat);
};

std::ostream& operator << (std::ostream &out, Form &in);

#endif
