/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 03:37:54 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/12 03:45:43 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap scav("paul");
	for (int i = 0; i < 51; i++)
		scav.attack("Michou");
	scav.guardGate();
	std::cout << scav.damage() << "\n";;
	std::cout << scav.hp() << "\n";;
	std::cout << scav.energy() << "\n";;
	return 0;
}
