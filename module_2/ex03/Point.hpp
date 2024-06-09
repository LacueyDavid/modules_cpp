/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:15:03 by dlacuey           #+#    #+#             */
/*   Updated: 2024/06/09 15:22:35 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &src);
	~Point();

	Point& operator=(const Point &rhs);

	Fixed getX(void) const;
	Fixed getY(void) const;
private:
	const Fixed x;
	const Fixed y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
