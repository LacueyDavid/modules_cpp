/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animals.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 00:30:27 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/24 09:16:02 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animals.hpp"
#include <iostream>

Animal::Animal(const std::string& type)
	: type(type)
{
}

Animal::~Animal()
{
	std::cout << "DTOR ANIMAL.\n";
}

Dog::Dog()
	: Animal("Dog")
{
	brain = new Brain();
	std::cout << "CTOR DOG\n";
}

Cat::Cat()
	: Animal("Cat")
{
	brain = new Brain();
	std::cout << "CTOR CAT\n";
}

void Animal::makeSound() const
{
}

void Cat::makeSound() const
{
	std::cout << "Meow.\n";
}

void Dog::makeSound() const
{
	std::cout << "Bark.\n";
}

std::string Animal::getType() const
{
	return type;
}

Dog::~Dog()
{
	delete(brain);
	std::cout << "DTOR DOG.\n";
}

Cat::~Cat()
{
	delete(brain);
	std::cout << "DTOR CAT.\n";
}
