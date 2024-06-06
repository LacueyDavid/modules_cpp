/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 00:32:51 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/02 01:15:48 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
private:
	int fixedPoint;
	static const int fractionalBits = 8; // static == appartient a la class (namespace)
};

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixedPoint);
