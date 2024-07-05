/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:21:03 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/05 22:53:01 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "character.hpp"

Character::Character()
	: inventory()
	, name()
{}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
		delete inventory[i];
}

Character::Character(const std::string &name)
    : inventory()
	, name(name)
{}

Character::Character(const Character &other)
    : inventory()
	, name(other.name)
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = other.inventory[i]->clone();
}

// si je dois faire une copy prend le par copy et pas par ref
Character &Character::operator=(Character other)
{
    other.swap(*this);
    for (int i = 0; i < 4; ++i)
        delete (other.inventory[i]); 
    return *this;
}

// au moment ou on a fait this les ref netaient pas inventé.

const std::string &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (inventory[i] == 0)
        {
            inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
    if (!inventory[idx])
        return;
    inventory[idx]->use(target);
}

void Character::swap(Character &other)
{
    std::swap(name, other.name);
    std::swap(inventory, other.inventory);
}

void swap(Character &lhs, Character &rhs)
{
    lhs.swap(rhs);
}
