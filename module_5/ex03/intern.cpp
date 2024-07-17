#include "intern.hpp"

#include <utility>
#include <iostream>

#include "shrubbery_creation_form.hpp"
#include "robotomy_request_form.hpp"
#include "presidential_pardon_form.hpp"

static const std::pair<std::string, AForm*(*)(const std::string&)> form_map[] =
{
  std::make_pair("shrubbery creation", Intern::createForm<ShrubberyCreationForm>),
  std::make_pair("robotomy request", Intern::createForm<RobotomyRequestForm>),
  std::make_pair("presidential pardon", Intern::createForm<PresidentialPardonForm>),

};

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	for (size_t i = 0; i < 3; ++i)
		if (form_map[i].first == name)
		{
			std::cout << "Intern creates " << name << "\n";
			return form_map[i].second(target);

		}

	std::cout << "Intern couldn't create " << name << "\n";
	return 0;
}
