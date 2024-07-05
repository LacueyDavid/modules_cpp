/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:20:59 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/03 18:10:19 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "icharacter.hpp"
#include "amateria.hpp"

class Character : public ICharacter
{
public:
	Character();
	virtual ~Character();
	Character(const std::string &name);
	Character(const Character &other);
	Character &operator=(Character other);
	const std::string &getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);
	virtual void swap(Character& other);

private:
	AMateria *inventory[4];
	std::string name;
};

void swap(Character& lhs, Character& rhs);

#endif
