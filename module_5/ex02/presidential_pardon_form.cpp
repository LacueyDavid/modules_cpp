#include "presidential_pardon_form.hpp"

#include <iostream>
#include <cstdlib>

#include "bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidential Pardon form", 25, 5)
	, target(target)
{
}

void PresidentialPardonForm::do_execute() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}
