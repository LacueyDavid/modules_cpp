#include "shrubbery_creation_form.hpp"
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery creation form", 145, 137)
	, target(target)
{
}

void ShrubberyCreationForm::do_execute() const
{
	std::string filename = target + "_shrubbery";
	std::ofstream ostrm(filename.c_str());
	ostrm << "todo arbre";
}

AForm* ShrubberyCreationForm::clone() const
{
	return new ShrubberyCreationForm(*this);
}
