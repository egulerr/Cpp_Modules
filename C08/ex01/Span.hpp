#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string;

class Span{
private:
	std::vector<int> numbers;
	size_t len;
public:
	Span();
	Span(unsigned int N);
	Span(const Span &ref);
	Span& operator = (const Span &ref);
	~Span();
	void addNumber(int num);
	int shortestSpan();
	int longestSpan();
	void printNumbers();
	void addNumberInRange(std::vector<int>::iterator start, std::vector<int>::iterator finish);
	struct notEnoughMemory : public std::exception{
		const char * what() const throw();
	};
};

#endif
