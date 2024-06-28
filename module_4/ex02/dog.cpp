/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:35:21 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/27 11:33:01 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"
#include <iostream>
#include "brain.hpp"

Dog::Dog()
	: Animal("Dog")
	, brain(new Brain())
{
	std::cout << "CTOR DOG\n";
}

Dog::Dog(const Dog &other)
	: Animal(other.type)
	, brain(new Brain(*other.brain))
{}

Dog &Dog::operator=(const Dog& other)
{
	if (this != &other)
		return *this;
	type = other.type;
	if (brain)
		delete (brain);
	brain = new Brain(*other.brain);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Bark.\n";
}

Dog::~Dog()
{
	std::cout << "DTOR DOG.\n";
	delete(brain);
}
void Dog::setIdea(const std::string &idea, int index)
{
	brain->setIdea(idea, index);
}

std::string	Dog::getIdea(int index)
{
	return brain->getIdea(index);
}
