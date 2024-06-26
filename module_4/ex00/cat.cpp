/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:35:57 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/26 11:20:59 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"
#include <iostream>

Cat::Cat(const Cat& other)
	: Animal(other.type)
{}

Cat &Cat::operator=(const Cat& other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

Cat::Cat()
	: Animal("Cat")
{
	std::cout << "CTOR CAT\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow.\n";
}

Cat::~Cat()
{
	std::cout << "DTOR CAT.\n";
}
