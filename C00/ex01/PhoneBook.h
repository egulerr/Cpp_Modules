#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contact.h"
#include <string>
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::string;

class PhoneBook
{
private:
	Contact contact[8];
public:
	void add(PhoneBook &book, int &index);
	void search(int index);
	void exit();
};
#endif