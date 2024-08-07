/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:28:53 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/16 22:58:13 by dlacuey          ###   ########.fr       */
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
		Bureaucrat rang_1("Thibaud", 1110);
	}
	catch (const std::exception& e)
	{
		std::cout << "I catch : " << e.what() << "\n";
	}
	Form f("myform", 42, 51);

	Bureaucrat too_low("Hubert", 99);
	too_low.signForm(f);
	rang_1.signForm(f);
	rang_1.downGrade();
	std::cout << rang_1 << "\n";
}
