#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		Contact();
		~Contact();
		bool		init(void);
		std::string	getFirstName(void) ;
		std::string	getLastName(void) ;
		std::string	getNickname(void) ;
		std::string	getPhoneNumber(void) ;
		std::string	getDarkestSecret(void) ;
};

#endif
