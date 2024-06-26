/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:39:26 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/26 10:15:45 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(){}

FragTrap::FragTrap(const FragTrap &other)
	: ClapTrap(other)
{}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this == &other)
		return *this;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	return *this;
}

FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name, initial_hp, initial_energy, initial_damage)
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
