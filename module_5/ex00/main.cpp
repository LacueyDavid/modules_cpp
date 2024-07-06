/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:28:53 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/06 16:39:15 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "bureaucrat.hpp"

int main()
{
	Bureaucrat rang_1("Thibaud", 1);
	try
	{
		rang_1.upGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "I catch : " << e.what() << "\n";
	}
	rang_1.downGrade();
	std::cout << rang_1 << "\n";
}
