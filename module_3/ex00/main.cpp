/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 03:37:54 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/11 03:43:18 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("ClapTrap");
	clap.attack("target");
	clap.takeDamage(3);
	clap.beRepaired(2);
	return 0;
}
