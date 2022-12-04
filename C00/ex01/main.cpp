#include "PhoneBook.h"

int main()
{
	string		input;
	PhoneBook	book;
	system("clear");
	int index = 0;

	while (1)
	{
		cout << "Enter one of the following contents:\nADD | SEARCH | EXIT\n\n" ;
		getline(cin, input);
		if (input == "ADD" || input == "SEARCH" || input == "EXIT")
		{
			if (input == "ADD")
				book.add(book, index);
			else if (input == "SEARCH")
				book.search(index);
			else if (input == "EXIT")
				book.exit();
		}
		else
			cout << "\nEnter correct argument." << "\n";
	}
}