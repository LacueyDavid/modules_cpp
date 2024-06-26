/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:34:39 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/26 10:03:17 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
public:
	ClapTrap();
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	ClapTrap(std::string name);
	virtual ~ClapTrap();
	unsigned int hp() { return hitPoints; }
	unsigned int energy() { return energyPoints; }
	unsigned int damage() { return attackDamage; }
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
protected:
	ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;
};

#endif
