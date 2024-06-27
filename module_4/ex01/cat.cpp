/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:35:57 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/27 11:33:35 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"
#include <iostream>
#include "brain.hpp"

Cat::Cat(const Cat& other)
	: Animal(other.type)
	, brain(new Brain(*other.brain))
{
}

Cat &Cat::operator=(const Cat& other)
{
	if (this != &other)
		return *this;
	type = other.type;
	if (brain)
		delete (brain);
	brain = new Brain(*other.brain);
	return *this;
}

Cat::Cat()
	: Animal("Cat")
	, brain(new Brain())
{
	std::cout << "CTOR CAT\n";
}

Cat::~Cat()
{
	std::cout << "DTOR CAT.\n";
	delete(brain);
}

void Cat::makeSound() const
{
	std::cout << "Meow.\n";
}


void Cat::setIdea(const std::string &idea, int index)
{
	brain->setIdea(idea, index);
}

std::string	Cat::getIdea(int index)
{
	return brain->getIdea(index);
}
