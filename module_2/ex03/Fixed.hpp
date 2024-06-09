/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 00:32:51 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/09 16:34:42 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class Fixed
{
public:
	Fixed();
	Fixed(const int number);
	Fixed(const float number);
	~Fixed();
	Fixed(const Fixed& other); // copy constructor (peut prendre par copy (sans ref) ou sans const(mais debile))
	Fixed& operator=(const Fixed&); // copy assignement operator (operator overload)
	Fixed operator+(const Fixed&);
	Fixed operator-(const Fixed&);
	Fixed operator/(const Fixed&);
	Fixed operator*(const Fixed&);
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	Fixed operator++(const int);
	Fixed& operator++();
	Fixed operator--(int);
	Fixed& operator--();
	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;
	static Fixed& min (Fixed &a, Fixed &b);
	static const Fixed& min (const Fixed &a, const Fixed &b);
	static Fixed& max (Fixed &a, Fixed &b);
	static const Fixed& max (const Fixed &a, const Fixed &b);
	static const Fixed zero();
	static const Fixed one();
private:
	int fixedPoint;
	static const int fractionalBits = 8; // static == appartient a la class (namespace)
};

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixedPoint);

#endif
