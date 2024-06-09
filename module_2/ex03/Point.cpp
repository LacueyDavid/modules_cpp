/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:22:53 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/09 15:28:17 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void)
	: x(0), y(0)
{
}

Point::Point(const float x, const float y)
	: x(x), y(y)
{
}

Point::Point(const Point &src)
	: x(src.x), y(src.y)
{
}

Point::~Point()
{
}

Point& Point::operator=(const Point &rhs)
{
	if (this != &rhs)
	{
		(Fixed) x = rhs.getX();
		(Fixed) y = rhs.getY();
	}
	return *this;
}

Fixed Point::getX(void) const
{
	return x;
}

Fixed Point::getY(void) const
{
	return y;
}
