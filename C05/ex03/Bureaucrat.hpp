#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
#include "Form.hpp"
using std::endl;
using std::string;
using std::cout;

class Form;

class Bureaucrat{
	private:
		const string	_name;
		int				_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &ref);
		Bureaucrat& operator = (const Bureaucrat &ref);
		~Bureaucrat();
		//--------------------------------------
		struct gradeTooHighException : public std::exception{
			const char * what() const throw();
		};
		struct gradeTooLowException : public std::exception{
			const char * what() const throw();
		};
		struct execTooLowException: public  std::exception{
			const char * what() const throw();
		};
		std::string	getName(){return _name;}
		int			getGrade() const {return _grade;}
		void		increment();
		void		decrement();
		void		signForm(Form &form);
		void		executeForm(Form const &form);
};

std::ostream& operator<<(std::ostream &out, Bureaucrat &in);

#endif
