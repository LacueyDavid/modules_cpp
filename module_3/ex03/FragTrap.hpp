/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:38:35 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/18 15:49:11 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(const std::string &name);
	virtual ~FragTrap();
	virtual void attack(const std::string &target);
	void highFivesGuys();
protected:
	static const unsigned int initial_hp = 100;
	static const unsigned int initial_energy = 100;
	static const unsigned int initial_damage = 30;
private:
	FragTrap (const FragTrap &);
	FragTrap &operator=(const FragTrap &);
};

#endif
