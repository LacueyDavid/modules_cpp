/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:24:22 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/03 17:48:20 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cure.hpp"
#include <iostream>

Cure::Cure()
	: AMateria("cure")
{}

Cure::Cure(const Cure &other)
	: AMateria(other)
{}

Cure::~Cure(){}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

Cure* Cure::clone() const
{
	Cure *clone;
	clone = new Cure();
	return clone;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
