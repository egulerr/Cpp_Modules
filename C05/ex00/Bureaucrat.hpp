#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat{
	private:
		const std::string _name;
		const int _grade;
	public:
		struct gradeTooHighException : public std::exception{
			const char * what() const throw();
		};
		struct gradeTooLowException : public std::exception{
			const char * what() const throw();
		};
		Bureaucrat(std::string name, int grade);
	std::string getName(){return _name;}
	int getGrade(){return _grade;}
		~Bureaucrat();
};

std::ostream& operator<<(std::ostream &out, Bureaucrat &in);

#endif
