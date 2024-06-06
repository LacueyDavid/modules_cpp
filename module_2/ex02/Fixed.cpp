/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:23:29 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/02 01:24:31 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <ostream>
#include <cmath>

Fixed::Fixed()
	: fixedPoint()
{}

Fixed::Fixed(const int number)
	: fixedPoint(number << Fixed::fractionalBits)
{}

Fixed::Fixed(const float number)
	: fixedPoint(static_cast<int>(roundf(number * (1 << Fixed::fractionalBits))))
{
}

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
Fixed Fixed::operator+(const Fixed& other)
{
	Fixed newFixedPoint;
	newFixedPoint.fixedPoint = fixedPoint + other.fixedPoint;
	return newFixedPoint;
}

Fixed Fixed::operator-(const Fixed& other)
{
	Fixed newFixedPoint;
	newFixedPoint.fixedPoint = fixedPoint - other.fixedPoint;
	return newFixedPoint;
}

Fixed Fixed::operator*(const Fixed& other)
{
	Fixed newFixedPoint;
	newFixedPoint.fixedPoint = (fixedPoint * other.fixedPoint) >> Fixed::fractionalBits;
	return newFixedPoint;
}

Fixed Fixed::operator/(const Fixed& other)
{
	Fixed newFixedPoint;
	return newFixedPoint;
}

bool Fixed::operator==(const Fixed& other) const
{
	return fixedPoint == other.fixedPoint;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return !(*this == other);
}

bool Fixed::operator<(const Fixed& other) const
{
	return fixedPoint < other.fixedPoint;
}

bool Fixed::operator>(const Fixed& other) const
{
	return other < *this;
}
bool Fixed::operator<=(const Fixed& other) const
{
	return !(*this > other);
}
bool Fixed::operator>=(const Fixed& other) const
{
	return !(*this < other);
}
std::ostream& operator<<(std::ostream& ostream, const Fixed& fixedPoint)
{
	ostream << fixedPoint.toFloat();
	return ostream;
}

int Fixed::getRawBits(void) const
{
	return fixedPoint;
}
void Fixed::setRawBits(int const raw)
{
	fixedPoint = raw;
}

int Fixed::toInt( void ) const
{
	return fixedPoint >> Fixed::fractionalBits;
}

float Fixed::toFloat( void ) const
{
	return static_cast<float>(fixedPoint) / (1 << Fixed::fractionalBits);
}
