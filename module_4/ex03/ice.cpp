/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:24:20 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/03 17:44:15 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ice.hpp"
#include <iostream>

Ice::Ice()
	: AMateria("ice")
{}

Ice::Ice(const Ice &other)
	: AMateria(other)
{}

Ice::~Ice(){}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

Ice* Ice::clone() const
{
	Ice *clone;
	clone = new Ice();
	return clone;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
