#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	contactCount = 0;
	totalContact = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destroyed" << std::endl;
}

std::string getFormattedField(const std::string& field)
{
	if (field.length() > 10)
		return field.substr(0,9) + ".";
	return field;
}

void display_contact_info(Contact contact)
{
	std::cout << std::endl;
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::addContact(void)
{
	Contact newContact;

	if (newContact.init())
	{
		contacts[totalContact] = newContact;
		if (contactCount < 8)
			contactCount++;
		if (totalContact < 8)
			totalContact++;
		if (totalContact == 8)
			totalContact = 0;
	}
}

void	PhoneBook::searchContact(void)
{
	std::string input;

	if (contactCount == 0)
	{
		std::cout << "There are no contacts to display!" << std::endl;
		return ;
	}
	std::cout << "\n|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < this->contactCount; i += 1)
	{
		std::cout << "|" << std::right << std::setw(10) << i + 1 << "|";
		std::cout << std::right << std::setw(10) << getFormattedField(contacts[i].getFirstName()) << "|" ;
		std::cout << std::right << std::setw(10) << getFormattedField(contacts[i].getLastName()) << "|";
		std::cout << std::right << std::setw(10) << getFormattedField(contacts[i].getNickname()) << "|";
		std::cout << std::endl;
	}
	std::cout << "enter the desired contact index\n desired contact: ";
	getline(std::cin, input);
	if (std::atoi(input.c_str()) >= 1 && std::atoi(input.c_str()) <= contactCount)
		display_contact_info(contacts[std::atoi(input.c_str()) - 1]);
	else
		std::cout << "invalid argument\n";
}
