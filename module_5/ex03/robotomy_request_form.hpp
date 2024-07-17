#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "aform.hpp"

class RobotomyRequestForm: public AForm
{
public:
	RobotomyRequestForm(const std::string& target);
	virtual void do_execute() const;
	virtual AForm* clone() const;

private:
	std::string target;
};

# endif
