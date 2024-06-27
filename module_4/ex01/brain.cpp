/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:51:16 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/27 11:22:11 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.hpp"

Brain::Brain(){}

Brain::~Brain(){}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

void Brain::setIdea(const std::string &idea, int index)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

std::string	Brain::getIdea(int index)
{
	if (index >= 0 && index < 100)
		return (ideas[index]);
	return ("no idea found");
}
