#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <deque>
#include <stack>
#include <list>
using std::cout;
using std::endl;
using std::string;

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>{
public:
	typedef typename Container::iterator iterator;
	MutantStack(){};
	MutantStack(const MutantStack<T> &ref){*this = ref;}
	MutantStack& operator = (const MutantStack<T> &ref){
		if (this != &ref)
		{
			std::cout << "Copy Assigment Operator Worked" << std::endl;
			return (*this);
		}
		return (*this);
	}
	~MutantStack(){ };
	iterator begin() { return(this->c.begin()); }
	iterator end() { return(this->c.end()); }
};

#endif
