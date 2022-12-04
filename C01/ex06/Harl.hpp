#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
using std::cout;
using std::string;

int	give_a_number(string str);

class Harl{
public:
	void	complain(std::string level);
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};

#endif
