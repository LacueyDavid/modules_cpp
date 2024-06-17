/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 02:35:38 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/13 21:08:17 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

// si energypoint doit etre init avant hitpoint, faut mettre energypoint avant
// hitpoints dans le .hpp

ClapTrap::ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage)
	: name(name)
	, hitPoints(hitPoints)
	, energyPoints(energyPoints)
	, attackDamage(attackDamage)
{
    std::cout << " CTOR CLAPTRAP\n";
}

ClapTrap::ClapTrap(std::string name)
	: name(name)
	, hitPoints(10)
	, energyPoints(10)
	, attackDamage(0)
{
    std::cout << name << " CTOR CLAPTRAP\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << name << " DTOR CLAPTRAP\n";
}

void ClapTrap::attack(std::string const& target)
{
	if (energyPoints)
	{
		std::cout << "ClapTrap " << name << " attacks " << target
			<< ", causing " << attackDamage << " points of damage!\n";
		energyPoints--;
		return;
	}
	std::cout << "ClapTrap " << name << " is unable to attack "
		<< target << "!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= amount)
	{
		std::cout << "ClapTrap " << name << "is dead!\n";
		hitPoints = 0;
		return;
	}
	std::cout << "ClapTrap " << name << " take " << amount << " point of damage!\n";
	hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints <= amount)
	{
		std::cout << "ClapTrap " << name << " is out of energy!\n";
		return;
	}
	std::cout << "ClapTrap " << name << " repair itself for " << amount << " HP!\n";
	energyPoints -= 1;
	hitPoints += amount;
}
