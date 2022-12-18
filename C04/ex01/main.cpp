#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(){
	const Animal *j = new Dog();
	std::cout << std::endl;
	const Animal *i = new Cat();
	std::cout << std::endl;
	WrongAnimal *a = new WrongCat();
	std::cout << std::endl;

	Dog basic;
	{
		Dog tmp = basic;
	}
	i->makeSound();
	j->makeSound();
	a->makeSound();
	delete j;
	std::cout << std::endl;
	delete i;
	std::cout << std::endl;
	delete a;
	return 0;
}