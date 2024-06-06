/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:23:29 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/01 23:30:40 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
	: fixedPoint(0)
{}

Fixed::~Fixed(){}

Fixed::Fixed(const Fixed& other)
	: fixedPoint(other.fixedPoint)
{

}

Fixed& Fixed::operator=(const Fixed& other)
{
	this->fixedPoint = other.fixedPoint;
	return *this;
}
int Fixed::getRawBits(void) const
{
	return fixedPoint;
}
void Fixed::setRawBits(int const raw)
{
	fixedPoint = raw;
}
