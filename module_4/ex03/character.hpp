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

class Character : public ICharacter
{
public:
	Character();
	~Character();
	Character(const std::string &name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	const std::string &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

private:
	AMateria *inventory[4];
	std::string name;
};

#endif
