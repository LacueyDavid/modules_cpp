#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <cstdlib>

class PhoneBook {
	private:
		int contactCount;
		int totalContact;
		Contact contacts[8];
	public:
		PhoneBook();
		~PhoneBook();
		void addContact();
		void searchContact();
		void printContacts();
};

#endif
