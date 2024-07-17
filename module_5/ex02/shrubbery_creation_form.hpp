#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include "aform.hpp"

class ShrubberyCreationForm: public AForm
{
public:
	ShrubberyCreationForm(const std::string& target);
	virtual void do_execute() const;

private:
	std::string target;
};

# endif
