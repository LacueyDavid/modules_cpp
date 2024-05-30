#include <iostream>
#include "contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

bool	check_input(std::string input)
{
	if (input.empty() || std::cin.eof())
	{
		std::cout << "you must add info for the contact.\n";
		return false;
	}
	return true;
}

bool	Contact::init(void)
{
	std::string input;

	std::cout << "firstname: ";
	getline(std::cin, input);
	if (!check_input(input))
		return false;
	this->firstName = input;
	std::cout << "lastname: ";
	getline(std::cin, input);
	if (!check_input(input))
		return false;
	this->lastName = input;
	std::cout << "nickname: ";
	getline(std::cin, input);
	if (!check_input(input))
		return false;
	this->nickName = input;
	std::cout << "phone number: ";
	getline(std::cin, input);
	if (!check_input(input))
		return false;
	this->phoneNumber = input;
	std::cout << "darkestSecret: ";
	getline(std::cin, input);
	if (!check_input(input))
		return false;
	this->darkestSecret = input;
	return true;
}

std::string Contact::getFirstName(void) {
    return firstName;
}

std::string Contact::getLastName(void) {
    return lastName;
}

std::string Contact::getNickname(void) {
    return nickName;
}

std::string Contact::getPhoneNumber(void) {
    return phoneNumber;
}

std::string Contact::getDarkestSecret(void) {
    return darkestSecret;
}
