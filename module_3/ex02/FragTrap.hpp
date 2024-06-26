/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:38:35 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/26 07:42:38 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
  FragTrap();
  FragTrap(const std::string &name);
  ~FragTrap();
  void attack(const std::string &target);
  void highFivesGuys();
  FragTrap(const FragTrap &other);
  FragTrap &operator=(const FragTrap &other);
};

#endif
