/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 03:37:54 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/11 09:23:39 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap clap("ClapTrap");
	clap.attack("target");
	clap.takeDamage(3);
	clap.beRepaired(2);
	ScavTrap scav("paul");
	scav.attack("Michou");
	scav.guardGate();
	std::cout << scav.damage() << "\n";;
	std::cout << scav.hp() << "\n";;
	std::cout << scav.energy() << "\n";;
	return 0;
}
