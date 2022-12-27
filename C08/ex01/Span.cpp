#include "Span.hpp"

Span::Span() {
	this->len = 0;
}

Span::Span(unsigned int N) {
	this->len = N;
}

Span::Span(const Span &ref) {
	*this = ref;
}

Span &Span::operator=(const Span &ref) {
	this->numbers = ref.numbers;
	return (*this);
}

Span::~Span() {}

const char *Span::notEnoughMemory::what() const throw() {
	return ("not enough memory");
}

void Span::printNumbers() {
	std::vector<int>::iterator i = numbers.begin();
	cout << "vector: ";
	while (i != numbers.end())
	{
		cout << *i++ << " ";
	}
	cout << endl;
}

void Span::addNumber(int num) {
	try {
		if (numbers.size() >= len)
			throw (notEnoughMemory());
		else
			numbers.push_back(num);
	} catch (std::exception &ex){
		cout << ex.what() << endl;
	}
}

int Span::longestSpan() {
	size_t i;

	i = *std::max_element(numbers.begin(), numbers.end()) - *std::min_element(numbers.begin(), numbers.end());

	return (i);
}

int Span::shortestSpan() {
	int min_range;
	int range;

	std::vector<int> copy = numbers;
	std::sort(copy.begin(), copy.end());
	std::vector<int>::iterator i = copy.begin();
	min_range = *(i) - *(i + 1);
	min_range = abs(min_range);
	while (i != copy.end())
	{
		range = abs(*(i) - *(i + 1));
		if (range < min_range)
			min_range = range;
		i++;
	}
	return (min_range);
}

void Span::addNumberInRange(std::vector<int>::iterator start, std::vector<int>::iterator finish) {
	while (start != finish)
		addNumber(*start++);
}