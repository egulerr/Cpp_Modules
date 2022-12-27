#include "Span.hpp"

int main(){
	Span sp = Span(10);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.printNumbers();
	std::cout <<"shortest range: " << sp.shortestSpan() << std::endl;
	std::cout <<"longest range: " <<sp.longestSpan() << std::endl;

	std::vector<int> number;
	number.push_back(35);
	number.push_back(45);
	number.push_back(55);
	number.push_back(65);
	number.push_back(75);
	number.push_back(85);
	sp.addNumberInRange(number.begin(), number.end());
	sp.printNumbers();
}