#include <iostream>
using std::cout;

int main(int ac, char **av)
{
    int	i;
	int j;

    if (ac == 1)
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else if (ac > 1)
    {
		i = 1;
        while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				av[i][j] = toupper(av[i][j]);
				j++;
			}
			i++;
		}
		i = 1;
		while (av[i])
		{
			cout << av[i];
			i++;
		}
    }
	cout << std::endl;
}