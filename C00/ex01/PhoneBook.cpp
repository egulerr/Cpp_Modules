#include "PhoneBook.h"

void PhoneBook::add(PhoneBook &book, int &index)
{
	string		name, surname, nickname, tel_num, secret;
	int i = index;

	if (index >= 8)
		i = index % 8;
	system("clear");
	cout << "Enter your name: ";
	getline(cin, name);
	cout << "Enter your surname: ";
	getline(cin, surname);
	cout << "Enter your nickname: ";
	getline(cin, nickname);
	cout << "Enter your telephone number: ";
	getline(cin, tel_num);
	cout << "Enter your darkest secret: ";
	getline(cin, secret);
	if (name.length() == 0 || surname.length() == 0 || nickname.length() == 0 || tel_num.length() == 0 || secret.length() == 0) {
		system("clear");
		cout << "Cannot be empty any contents.\nAdding failed.\n\n";
	}
	else
	{
		book.contact[i].setName(name);
		book.contact[i].setSurname(surname);
		book.contact[i].setNickname(nickname);
		book.contact[i].setPhoneNumber(tel_num);
		book.contact[i].setSecret(secret);
		system("clear");
		cout << "Successfully added.\n\n";
		index++;
	}
}

void PhoneBook::search(int index)
{
	string	buff;
	char	input;
	string	stop;
	int		i;
	int		j;

	if (index >= 8)
		j = 8;
	else
		j = index;
	system("clear");
	cout << std::setw(10) << "INDEX";
	cout << "|" << std::setw(10) << "NAME";
	cout << "|" << std::setw(10) << "SURNAME";
	cout << "|" << std::setw(10) << "NICKNAME" << "|" << std::endl;
	cout << "--------------------------------------------" << std::endl;
	i = 0;
	while (i < j)
	{
		cout << std::setw(10) << i+1 << "|" << std::setw(10);
		if (contact[i].getName().length() >= 10)
		{
			buff = contact[i].getName().substr(0,9);
			buff.push_back('.');
			cout << buff << "|" << std::setw(10);
		}
        else
		{
            cout << contact[i].getName() << "|" << std::setw(10);
        }
		if (contact[i].getSurname().length() >= 10)
		{
			buff = contact[i].getSurname().substr(0,9);
			buff.push_back('.');
			cout << buff << "|" << std::setw(10);
		}
		else
		{
			cout << contact[i].getSurname() << "|" << std::setw(10);
		}
		if (contact[i].getNickname().length() >= 10)
		{
			buff = contact[i].getNickname().substr(0,9);
			buff.push_back('.');
			cout << buff << "|" << std::endl;
		}
		else
		{
			cout << contact[i].getNickname() << "|" << std::endl;
		}
		i++;
	}
	cout << "\nEnter the \"INDEX\" you want to see:\n";
	cin >> input;
	if ((input - 48) <= j && (input - 48) > 0)
	{
		cout << "Name: " << contact[(input - 48) - 1].getName() << std::endl;
		cout << "Surname: " << contact[(input - 48) - 1].getSurname() << std::endl;
		cout << "Nickname: " << contact[(input - 48) - 1].getNickname() << std::endl;
		cout << "Telephone Number: " << contact[(input - 48) - 1].getPhoneNumber() << std::endl;
		cout << "Darkest Secret: " << contact[(input - 48) - 1].getSecret() << std::endl;
		cout << "\nPress any key.\n";
		getline(cin, stop);
		getline(cin, stop);
		system("clear");
	}
	else
	{
		system("clear");
		cout << "You entered an incorrect argument.\nPress any key.\n\n";
		getline(cin, stop);
		getline(cin, stop);
	}
}

void PhoneBook::exit()
{
	std::exit(0);
}