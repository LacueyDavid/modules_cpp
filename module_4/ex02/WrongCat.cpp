/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:35:57 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/26 11:40:14 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

Wrongcat::Wrongcat(const Wrongcat& other)
	: Wronganimal(other.type)
{}

Wrongcat &Wrongcat::operator=(const Wrongcat& other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

Wrongcat::Wrongcat()
	: Wronganimal("Wrongcat")
{
	std::cout << "CTOR Wrongcat\n";
}

void Wrongcat::makeSound() const
{
	std::cout << "Wrong Meow.\n";
}

Wrongcat::~Wrongcat()
{
	std::cout << "DTOR Wrongcat.\n";
}
