#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
using std::endl;
using std::cout;
using std::string;


template<typename T>
void iter(T *arr, int n, void(*fun)(T const &x)) {
	for (int i = 0; i < n; i++)
		fun(arr[i]);
}

template<typename T>
void fun(T const &x) {
	cout << x << endl;
}


#endif
