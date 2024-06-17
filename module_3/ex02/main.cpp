/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 03:37:54 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/13 19:43:48 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
	FragTrap jean("Jean");
	ScavTrap ok("oui");
	ClapTrap *haru = new ClapTrap("haru");
	ClapTrap *mouse = new FragTrap("mouse");
	ClapTrap *kad = new ScavTrap("kad");
	haru->attack("mouse");
	mouse->attack("kad");
	kad->attack("mouse");
	// jean.attack("target");
	// FragTrap david("David");
	// FragTrap ludo("Ludo");
	// FragTrap thibaut("Thibaut");
	// FragTrap pierre("PIERRE");
	return 0;
}
