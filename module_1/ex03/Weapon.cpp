/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:10:35 by dlacuey           #+#    #+#             */
/*   Updated: 2024/05/30 19:21:22 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
	: type(type)
{}

const std::string& Weapon::getType()
{
	return type;
}

void Weapon::setType( const std::string& newType )
{
	type = newType;
}
