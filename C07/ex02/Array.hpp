#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
using std::endl;
using std::string;
using std::cout;

template <typename T>
class Array{
private:
	unsigned int    _size;
	T               *_arr;
public:
	Array();
	Array(unsigned int size);
	Array(const Array &cpy);
	Array &operator=(const Array &assign);
	~Array();
	T const &operator[](const unsigned int index) const;
	T &operator[](const unsigned int index);
	unsigned int size();
};

template<typename T>
Array<T>::Array() : _size(0), _arr(0) {}

template<typename T>
Array<T>::Array(unsigned int size) : _size(size), _arr(0) {
	if (_size > 0) {
		_arr = new T[_size];
	}
}

template<typename T>
Array<T>::Array(Array const & a) {
	_size = 0;
	_arr = 0;
	*this = a;
}

template<typename T>
Array< T >::~Array() {
	if (_size > 0) {
		delete [] _arr;
	}
}

template<typename T>
Array<T> &Array<T>::operator=(Array const & a) {
	if (this != &a) {
		if (_size > 0) {
			delete [] _arr;
		}
		_size = a._size;
		_arr = 0;
		if (_size > 0) {
			_arr = new T[_size];
			for (unsigned i = 0; i < _size; ++i) {
				_arr[i] = a._arr[i];
			}
		}
	}
	return (*this);
}

template<typename T>
T const &Array<T>::operator[](const unsigned int index) const {
	cout << "selam" << endl;
	int x = index;
	if (index >= _size || x < 0)
		throw(std::out_of_range("out of range"));
	else
		return (_arr[index]);
}

template<typename T>
T & Array<T>::operator[](const unsigned int index) {
	int x = index;
	if (index >= _size || x < 0) {
		throw (std::out_of_range("out of range"));
	}
		else
		return (_arr[index]);
}

template<typename T>
unsigned int Array<T>::size() {
	return (_size);
}

#endif
