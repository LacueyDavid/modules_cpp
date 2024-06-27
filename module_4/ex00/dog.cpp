/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:35:21 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/26 11:20:24 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"
#include <iostream>

Dog::Dog()
	: Animal("Dog")
{
	std::cout << "CTOR DOG\n";
}

Dog::Dog(const Dog &other)
	: Animal(other.type)
{}

Dog &Dog::operator=(const Dog& other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Bark.\n";
}

Dog::~Dog()
{
	std::cout << "DTOR DOG.\n";
}