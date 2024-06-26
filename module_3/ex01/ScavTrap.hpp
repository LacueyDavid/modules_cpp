/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:38:35 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/26 07:38:06 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(const std::string &name);
	virtual ~ScavTrap();
	virtual void attack(const std::string &target);
	void guardGate();
	ScavTrap();
	ScavTrap (const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
};
