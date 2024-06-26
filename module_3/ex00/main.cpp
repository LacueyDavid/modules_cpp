/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 03:37:54 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/26 07:27:06 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("ClapTrap");
	clap.attack("target");
	clap.takeDamage(3);
	clap.beRepaired(2);
	ClapTrap copyclap(clap);
	copyclap.attack("target");
	copyclap.takeDamage(3);
	copyclap.beRepaired(2);
	copyclap.takeDamage(2);
	clap = copyclap;
	clap.beRepaired(1);
	return 0;
}
