#include "Brain.hpp"

Brain::Brain() {
	cout << "Brain default constructor called." << endl;
}
Brain::~Brain() {
	cout << "Brain destructor called." << endl;
}

Brain::Brain(const Brain &ref) {
	*this = ref;
}

Brain &Brain::operator=(const Brain &ref) {
	for (int i = 0; i < 100; i++){
		this->ideas[i] = ref.ideas[i];
	}
	cout << "Brain copy called." << endl;
	return (*this);
}