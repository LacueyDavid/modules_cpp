/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:21:03 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/03 18:09:50 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "character.hpp"

Character();
~Character();
Character(const std::string &name);
Character(const Character &other);
Character &operator=(const Character &other);
const std::string &getName() const;
void equip(AMateria *m);
void unequip(int idx);
void use(int idx, ICharacter &target);
