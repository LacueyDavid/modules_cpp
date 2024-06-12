/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:34:39 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/12 03:48:13 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
public:
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	ClapTrap(std::string name);
	ClapTrap(std::string name, unsigned int hitPoints,
			unsigned int energyPoints, unsigned int attackDamage);
	~ClapTrap();
	unsigned int hp() { return hitPoints; }
	unsigned int energy() { return energyPoints; }
	unsigned int damage() { return attackDamage; }
protected:
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;
	ClapTrap();
	ClapTrap(const ClapTrap &);
	ClapTrap &operator=(const ClapTrap &);
};

#endif
