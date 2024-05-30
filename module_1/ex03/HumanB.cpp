/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:15:13 by dlacuey           #+#    #+#             */
/*   Updated: 2024/05/30 19:30:17 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(std::string name)
	: name(name)
{
	weapon = NULL;
}

void	HumanB::attack()
{
	if (weapon != NULL && weapon->getType() != "")
		std::cout << name << " attacks with their " << weapon->getType() << "\n";
}

void	HumanB::setWeapon( Weapon& weapon )
{
	this->weapon = &weapon;
}
