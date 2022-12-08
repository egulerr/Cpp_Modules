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
		Form(const string name, int gradeToSign, int gradeToExecute);
		Form(const Form &ref);
		Form& operator = (const Form &ref);
		virtual ~Form();
		const string getName()const{return (name);}
		bool getSign() const {return (sign);}
		int getGradeToSign() const {return (gradeToSign);}
		int getGradeToExecute() const {return (gradeToExecute);}
		struct gradeTooHighException: public std::exception{
			const char * what() const throw();
		};
		struct gradeTooLowException: public std::exception{
			const char * what() const throw();
		};
		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream& operator << (std::ostream &out, Form &in);

#endif
