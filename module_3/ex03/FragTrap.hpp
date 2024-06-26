/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:38:35 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/26 10:05:01 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap
{
  public:
	FragTrap();
	FragTrap(const std::string &name);
	virtual ~FragTrap();
	virtual void attack(const std::string &target);
	void         highFivesGuys();
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);

  protected:
	static const unsigned int initial_hp = 100;
	static const unsigned int initial_energy = 100;
	static const unsigned int initial_damage = 30;
};

#endif
