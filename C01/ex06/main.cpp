#include "Harl.hpp"

int	give_a_number(string str)
{
	int in;

	if (str == "DEBUG")
		in = 3;
	else if (str == "INFO")
		in = 2;
	else if (str == "WARNING")
		in = 1;
	else if (str == "ERROR")
		in = 0;
	else
		in = 4;
	return (in);
}

int main(int ac, char **av)
{
	Harl	obj;
	string	str;
	int		in;

	if (ac == 2)
	{
		str = av[1];
		in = give_a_number(str);
		while (in >= 0)
		{
			switch (in) {
				case 0:
					obj.complain("ERROR");
					break;
				case 1:
					obj.complain("WARNING");
					break;
				case 2:
					obj.complain("INFO");
					break;
				case 3:
					obj.complain("DEBUG");
					break;
				default:
					cout << " [ Probably complaining about insignificant problems ]\n";
					exit (0);
			}
			in--;
		}
	}
	else
		cout << "Incorrect entry.\n";
}