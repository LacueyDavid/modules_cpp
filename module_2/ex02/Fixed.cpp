/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:23:29 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/07 14:17:44 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
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
	Fixed result;
	int64_t x;
	if (other.getRawBits() == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return (result);
	}
	x = static_cast<int64_t>(this->getRawBits()) * (1 << result.fractionalBits);
	result.setRawBits(x / other.getRawBits());
	return result;
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

Fixed Fixed::operator++(const int)
{
	Fixed tmp(*this);
	tmp.fixedPoint = this->fixedPoint++;
	return tmp;
}
Fixed& Fixed::operator++()
{
	++this->fixedPoint;
	return *this;
}
Fixed Fixed::operator--(const int)
{
	Fixed tmp(*this);
	tmp.fixedPoint = this->fixedPoint--;
	return tmp;
}
Fixed& Fixed::operator--()
{
	--this->fixedPoint;
	return *this;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return a.getRawBits() < b.getRawBits() ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return a.getRawBits() < b.getRawBits() ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return a.getRawBits() > b.getRawBits() ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return a.getRawBits() > b.getRawBits() ? a : b;
}
