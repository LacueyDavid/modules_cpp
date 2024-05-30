#include <iostream>
#include "phonebook.hpp"

void	printInfos(void)
{
	std::cout << "ADD - add new contact\n";
	std::cout << "SEARCH - display a contact\n";
	std::cout << "EXIT - Exit Phonebook\n";
}

int main()
{
	std::string input;
	PhoneBook book;

	printInfos();
	while(true)
	{
		std::cout << "PhoneBook: ";
		getline(std::cin, input);
		if (input == "EXIT" || std::cin.eof())
			break;
		else if (input == "ADD")
			book.addContact();
		else if (input == "SEARCH")
			book.searchContact();
		else
			std::cout << "Invalid command" << "\n";
	}
	return 0;
}
