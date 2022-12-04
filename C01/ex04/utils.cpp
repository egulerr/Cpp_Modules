#include "Sed.hpp"

string read_dir(char *path)
{
	string			temp;
	std::fstream	my_file;

	my_file.open(path, std::ios::in);
	if (!my_file.is_open()) {
		cout << "No such file.\n";
	}
	else {
		char	c;
		while (my_file.get(c)) {
			temp.push_back(c);
		}
	}
	my_file.close();
	return (temp);
}
string	change_val(string s1, string s2, string res) {
	int	found = 0;

	while (1) {
		found = res.find(s1);
		if (found != -1) {
			res.erase(found, s1.length());
			res.insert(found, s2);
		} else
			break;
	}
	return (res);
}

void	write_dir(string res, char *path)
{
	string new_str;
	std::fstream my_file;

	new_str = path;
	new_str += ".replace";
	my_file.open(path, std::ios::in);
	if (my_file) {
		my_file.close();
		my_file.open(new_str, std::ios::out);
		my_file << res;
	}
	my_file.close();
}