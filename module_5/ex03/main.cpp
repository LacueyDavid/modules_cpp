/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:28:53 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/17 01:19:19 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "bureaucrat.hpp"
#include "shrubbery_creation_form.hpp"
#include "presidential_pardon_form.hpp"
#include "robotomy_request_form.hpp"
#include "intern.hpp"

int main()
{
	Bureaucrat rang_1("Thibaud", 1);
	try
	{
		rang_1.upGrade();
		Bureaucrat rang_1("Thibaud", 1110);
	}
	catch (const std::exception& e)
	{
		std::cout << "I catch : " << e.what() << "\n";
	}
	Bureaucrat too_low("Hubert", 99);
	rang_1.downGrade();
	std::cout << rang_1 << "\n";
	ShrubberyCreationForm f2("david");
	rang_1.signForm(f2);
	rang_1.executeForm(f2);
	PresidentialPardonForm f3("benoit");
	rang_1.signForm(f3);
	rang_1.executeForm(f3);
	RobotomyRequestForm f4("kevin");
	rang_1.signForm(f4);
	rang_1.executeForm(f4);

	Intern i;

	AForm* f = i.makeForm("presidential pardon", "jeanmich");
	std::cout << *f << "\n";
	delete f;

	AForm* lol = i.makeForm("non existing", "jeanmich");
	delete lol;
}
