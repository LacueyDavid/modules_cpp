/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:39:26 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/18 15:50:38 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string &name)
	: ClapTrap(name, initial_hp, initial_energy, initial_damage)
{
	std::cout << name << " CTOR SCAVTRAP\n";
}
ScavTrap::~ScavTrap()
{
	std::cout << name << " DTOR SCAVTRAP\n";
	// va donner le nom de claptrap car scavtrap n'a pas de champ name
}

void ScavTrap::attack(const std::string &target)
{
	if (energyPoints == 0 || hitPoints == 0)
	{
		std::cout << "ScavTrap " << name << " is unable to attack " << target
			<< "!\n";
		return ;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
		<< attackDamage << " points of damage!\n";
	energyPoints -= 1;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gatekeeper mode!\n";
}
