#include "robotomy_request_form.hpp"

#include <iostream>
#include <cstdlib>

#include "bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy request form", 72, 45)
	, target(target)
{
}

void RobotomyRequestForm::do_execute() const
{
	std::cout << "brzzzz\n";
	srand(time(0));
	if (rand() % 2 == 0)
		std::cout << target << " successfully robotomized.\n";
	else
		std::cout << target << " couldn't be robotomized.\n";
}

AForm* RobotomyRequestForm::clone() const
{
	return new RobotomyRequestForm(*this);
}
