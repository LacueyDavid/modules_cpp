/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:39:26 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/13 21:07:42 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name, 100, 100, 30)
{
	std::cout << name << " CTOR FRAGTRAP\n";
}
FragTrap::~FragTrap()
{
	std::cout << name << " DTOR FRAGTRAP\n";
}

void FragTrap::attack(const std::string &target)
{
	if (energyPoints == 0 || hitPoints == 0)
	{
		std::cout << "FragTrap " << name << " is unable to attack " << target
			<< "!\n";
		return ;
	}
	std::cout << "FragTrap " << name << " attacks " << target << ", causing "
		<< attackDamage << " points of damage!\n";
	energyPoints -= 1;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " requests a high fives!\n";
}
