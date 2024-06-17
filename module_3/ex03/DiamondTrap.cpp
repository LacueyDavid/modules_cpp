/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:39:26 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/17 07:35:17 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string &myName)
	: ClapTrap(myName + "_clap_name")
	, ScavTrap(myName)
	, FragTrap(myName)
	, name(myName)
{
	std::cout << name << " CTOR DIAMONDTRAP\n";
	// std::cout << ClapTrap::name << " CTOR DIAMONDTRAP CLAPTRAP NAME\n";
}
DiamondTrap::~DiamondTrap()
{
	std::cout << name << " DTOR DIAMONDTRAP\n";
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

// 0: polymorphisme cest une maniere davoir de la genericité
// 1: lheritage est une facon davoir du polymorphisme
// 2: class base et class derivé
// 3: 
