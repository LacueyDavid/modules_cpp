/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:15:13 by dlacuey           #+#    #+#             */
/*   Updated: 2024/05/30 19:31:13 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon)
	: name(name)
	, weapon(weapon)
{}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}
