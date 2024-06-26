/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:38:35 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/26 10:06:56 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : virtual public ClapTrap // virtual ici dit : dans le
                                         // constructeur de scavtrap, ne
                                         // construit pas automatiquement claptrap,
                                         // pour eux et tous les enfants qui
                                         // heritent de scavtrap et fragtrap
{
  public:
	ScavTrap();
	ScavTrap(const std::string &name);
	virtual ~ScavTrap();
	virtual void attack(const std::string &target);
	void         guardGate();
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);

  protected:
	static const unsigned int initial_hp = 100;
	static const unsigned int initial_energy = 50;
	static const unsigned int initial_damage = 20;
};

#endif
