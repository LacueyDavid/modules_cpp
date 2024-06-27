/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 00:30:27 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/26 11:38:26 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

Wronganimal::Wronganimal(){}

Wronganimal::Wronganimal(const Wronganimal& other)
	: type(other.type)
{}

Wronganimal &Wronganimal::operator=(const Wronganimal &other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

Wronganimal::Wronganimal(const std::string& type)
	: type(type)
{
}

Wronganimal::~Wronganimal()
{
	std::cout << "DTOR WRONGANIMAL.\n";
}

void Wronganimal::makeSound() const
{
	std::cout << "test concluant\n";
}

std::string Wronganimal::getType() const
{
	return type;
}
