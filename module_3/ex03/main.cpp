/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 03:37:54 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/18 15:59:59 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	// FragTrap jean("Jean");
	// jean.attack("target");
	// FragTrap david("David");
	// FragTrap ludo("Ludo");
	// FragTrap thibaut("Thibaut");
	// FragTrap pierre("PIERRE");
	DiamondTrap diam("diam");
	diam.printStats();
	diam.whoAmI();
	diam.attack("benoit");
	return 0;
}
