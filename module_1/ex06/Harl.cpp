/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:58:40 by dlacuey           #+#    #+#             */
/*   Updated: 2024/05/31 16:26:30 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
	std::cout << "debug\n";
}

void Harl::info(void)
{
	std::cout << "info\n";
}

void Harl::warning(void)
{
	std::cout << "warning\n";
}

void Harl::error(void)
{
	std::cout <<"error\n";
}

void Harl::complain(std::string level)
{
	int i = 0;

	while (i < 5 && functions[i].first != level)
		i++;
	switch (i)
	{
		case 0:
			(this->*functions[i].second)();
			i++;
		case 1:
			(this->*functions[i].second)();
			i++;
		case 2:
			(this->*functions[i].second)();
			i++;
		case 3:
			(this->*functions[i].second)();
			i++;
			break;
		default:
			std::cout << "usless speaking\n";
	}
}

Harl::Harl()
{
	functions[0].first = "DEBUG";
	functions[1].first = "INFO";
	functions[2].first = "WARNING";
	functions[3].first = "ERROR";
	functions[0].second = &Harl::debug;
	functions[1].second = &Harl::info;
	functions[2].second = &Harl::warning;
	functions[3].second = &Harl::error;
}
