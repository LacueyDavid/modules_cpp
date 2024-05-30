/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:58:40 by dlacuey           #+#    #+#             */
/*   Updated: 2024/05/31 00:33:12 by dlacuey          ###   ########.fr       */
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

void Harl::complain(std::string level)
{
	for(size_t i = 0; i < 4; i++)
	{
		if (functions[i].first == level)
			(this->*functions[i].second)();
	}
}
