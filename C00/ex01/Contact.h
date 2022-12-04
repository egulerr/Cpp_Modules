#ifndef CONTACT_H
#define CONTACT_H
#include "PhoneBook.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::cin;
class Contact
{
private:
	string	name;
	string	surname;
	string	nickname;
	string	phone_number;
	string	secret;
public:
    void setName(string _name){name = _name;}
	void setSurname(string _surname){surname = _surname;}	
	void setNickname(string _nickname){nickname = _nickname;}
	void setPhoneNumber(string _phone_number){phone_number = _phone_number;}
	void setSecret(string _secret){secret = _secret;}
	string getName(){return (name);}
	string getSurname(){return (surname);}
	string getNickname(){return (nickname);}
	string getPhoneNumber(){return (phone_number);}
	string getSecret(){return (secret);}
};

#endif