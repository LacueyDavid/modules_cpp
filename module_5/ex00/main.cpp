/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:28:53 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/16 17:17:47 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "bureaucrat.hpp"

int main()
{
	Bureaucrat rang_1("Thibaud", 1);
	try
	{
		rang_1.upGrade(); // une exception == on sarrete
		Bureaucrat rang_1000("Thibaud", 1000);
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "I catch : " << e.what() << "\n";
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "I catch : " << e.what() << "\n";
	}
	rang_1.downGrade();
	std::cout << rang_1 << "\n";
}
