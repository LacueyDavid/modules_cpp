/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:38:35 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/26 10:11:26 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	virtual ~DiamondTrap();
	void attack(const std::string &target);
	void whoAmI();
	void printStats();
	DiamondTrap (const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &other);
protected:
	static const unsigned int initial_hp = FragTrap::initial_hp;
	static const unsigned int initial_energy = ScavTrap::initial_energy;
	static const unsigned int initial_damage = FragTrap::initial_damage;
private:
	std::string name; //pas le meme name que dans claptrap! il y en
					  //literalement 2 different
					  //ne pas faire car shadowing, name cache claptrap::name
					  //car un seul peut etre nommé sans le ::
};

#endif
