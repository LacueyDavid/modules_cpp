/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:35:21 by dlacuey           #+#    #+#             */
/*   Updated: 2024/05/29 21:01:19 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	randomChump("toto");
	Zombie* lol = newZombie("tata");
	lol->announce();
	delete lol;
	Zombie* horde = zombieHorde(4, "Albert");
	for(int i = 0; i < 4; i++)
		horde[i].announce();
	delete[] horde;
}
