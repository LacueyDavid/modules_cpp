/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 02:35:38 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/26 07:39:06 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){}

ClapTrap::ClapTrap(const ClapTrap& other)
	: name(other.name)
	, hitPoints(other.hitPoints)
	, energyPoints(other.energyPoints)
	, attackDamage(other.attackDamage)
{
	std::cout << "copy constructor called.\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
	//toujours protéger lui meme
	if (this == &other)
		return *this;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	// return *this pour le chaining
	return *this;
}

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
    std::cout << " CTOR CLAPTRAP\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << " DTOR CLAPTRAP\n";
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
