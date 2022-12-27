#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;


template<typename T>
void easyfind(T &t, int num){
	std::vector<int>::iterator it = std::find(t.begin(),t.end(), num);
	if (it == t.end())
		cout << "Not found" << endl;
	else
		cout << "Found at index: "<< it - t.begin() << endl;
}

#endif
