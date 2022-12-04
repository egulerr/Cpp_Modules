#include "Sed.hpp"

int main(int ac, char **av)
{
	string s1, s2, res;

	if (ac == 4)
	{
		s1 = av[2];
		s2 = av[3];
		res = read_dir(av[1]);
		res = change_val(s1, s2, res);
		write_dir(res, av[1]);
	}
	else
		cout << "Incorrect enter.\n";
}