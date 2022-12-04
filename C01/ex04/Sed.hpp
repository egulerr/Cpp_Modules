#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <sys/stat.h>
#include <fstream>
using std::string;
using std::cout;

string	read_dir(char *path);
string	change_val(string s1, string s2, string res);
void	write_dir(string res, char *path);

#endif
