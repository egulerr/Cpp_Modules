#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(){
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	WrongAnimal *a = new WrongCat();

	i->makeSound();
	j->makeSound();
	a->makeSound();
	delete j;
	delete i;
	delete a;
	return 0;
}