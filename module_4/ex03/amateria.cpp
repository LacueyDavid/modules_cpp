/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:28:30 by dlacuey           #+#    #+#             */
/*   Updated: 2024/07/05 22:38:35 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "amateria.hpp"
#include "icharacter.hpp"

AMateria::AMateria()
	: type("default")
{}

AMateria::AMateria(const AMateria &other)
	: type(other.type)
{}

AMateria::~AMateria(){}

AMateria::AMateria(std::string const &type)
	: type(type)
{}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* does nothing to " << target.getName() << "*\n";
}
