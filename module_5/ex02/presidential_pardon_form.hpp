#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include "aform.hpp"

class PresidentialPardonForm: public AForm
{
public:
	PresidentialPardonForm(const std::string& target);
	virtual void do_execute() const;

private:
	std::string target;
};

# endif
