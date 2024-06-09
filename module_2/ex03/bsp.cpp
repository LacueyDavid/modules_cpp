/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:29:36 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/09 16:57:17 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	isBetweenZeroAndOne(const Fixed& x)
{
	return Fixed::zero() <= x && x <= Fixed::one();
}

bool	isInTriangle(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3
					, Fixed x, Fixed y)
{
	Fixed denominator = ((y2 - y3)*(x1 - x3) + (x3 - x2)*(y1 - y3));

	Fixed a = ((y2 - y3)*(x - x3) + (x3 - x2)*(y - y3)) / denominator;
	Fixed b = ((y3 - y1)*(x - x3) + (x1 - x3)*(y - y3)) / denominator;
	Fixed c = Fixed(1) - a - b;

	return isBetweenZeroAndOne(a)
		&& isBetweenZeroAndOne(b)
		&& isBetweenZeroAndOne(c);
}

static bool isOnEdgeOrAVertex(Point const a, Point const b, Point const c,
							Point const point)
{
	return ((point.getY() - a.getY()) * (b.getX() - a.getX())
			- (point.getX() - a.getX()) * (b.getY() - a.getY()) == 0
	|| (point.getY() - a.getY()) * (c.getX() - a.getX())
	- (point.getX() - a.getX()) * (c.getY() - a.getY()) == 0
	|| (point.getY() - c.getY()) * (b.getX() - c.getX())
	- (point.getX() - c.getX()) * (b.getY() - c.getY()) == 0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool	check_in;
	
	check_in = isInTriangle(a.getX(), a.getY()
						, b.getX(), b.getY()
						, c.getX(), c.getY()
						, point.getX(), point.getY());
	if (isOnEdgeOrAVertex(a, b, c, point))
		return false;
	return check_in;
}
