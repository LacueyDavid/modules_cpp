/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:35:21 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/24 09:36:51 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"
#include <iostream>

Dog::Dog()
	: Animal("Dog")
{
	std::cout << "CTOR DOG\n";
}

void Dog::makeSound() const
{
	std::cout << "Bark.\n";
}
Dog::~Dog()
{
	std::cout << "DTOR DOG.\n";
}
