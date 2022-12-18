#include "converts.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		float input;
		string str = av[1];
		try{
			input = stof(str);
			all_converts(input);
		} catch (std::exception &ex){
			cout << "Incorrect input" << endl;
		}
	}
	else
		cout << "Incorrect input" << endl;
}