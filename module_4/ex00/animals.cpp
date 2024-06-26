/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animals.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 00:30:27 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/24 09:36:58 by dlacuey          ###   ########.fr       */
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

void Animal::makeSound() const
{
}

std::string Animal::getType() const
{
	return type;
}
