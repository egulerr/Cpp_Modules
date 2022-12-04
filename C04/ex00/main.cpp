#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(){
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* a = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();

	cout << j->getType() << " " << endl;
	cout << i->getType() << " " << endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	cout << "----W-I-T-H-O-U-T---V-I-R-T-U-A-L----" << endl;
	a->makeSound();
	k->makeSound(); //WrongAnimal classında ki makeSound' a gider çünkü virtual tagi yok.
	cout << "-------------------------------------" << endl;
	delete meta;
	delete j;
	delete i;
	delete a;
	delete k;
}