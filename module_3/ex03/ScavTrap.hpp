/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:38:35 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/18 15:49:53 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap // virtual ici dit : dans le constructeur de scavtrap,
										 // ne construit pas automatiquement
										 // claptrap, pour eux et tous les
										 // enfants qui heritent de scavtrap et
										 // fragtrap
{
public:
	ScavTrap(const std::string &name);
	virtual ~ScavTrap();
	virtual void attack(const std::string &target);
	void guardGate();
protected:
	static const unsigned int initial_hp = 100;
	static const unsigned int initial_energy = 50;
	static const unsigned int initial_damage = 20;
private:
	ScavTrap (const ScavTrap &);
	ScavTrap &operator=(const ScavTrap &);
};

#endif
