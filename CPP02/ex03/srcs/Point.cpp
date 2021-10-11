/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:02:05 by clorin            #+#    #+#             */
/*   Updated: 2021/09/15 13:02:19 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Point.hpp"

/* ---------------------------------------------------------
						canonical form
------------------------------------------------------------*/
Point::Point( void ): x(0), y(0)
{
	return;
}

Point::Point( Point const &rsh): x(Fixed(rsh.getX())), y(Fixed(rsh.getY()))
{
	return;
}

Point::~Point( void )
{
	return;
}

Point	&Point::operator=(Point const &rsh)
{
	/*There is a problem with the subject: 
	Indeed, we cannot overload an assignment operator while
	the private member variables x & y are const.*/
	return *this;
}

Point::Point(Fixed const &f1, Fixed const &f2): x(f1), y(f2)
{
	return;
}

/*-------------------------------------------------------------
								Getter
---------------------------------------------------------------*/

Fixed	const	&Point::getX( void ) const
{
	return this->x;
}

Fixed const 	&Point::getY( void ) const
{
	return this->y;
}

/*--------------------------------------------------------------
							Comparaison
-----------------------------------------------------------------*/

bool    Point::operator==( Point const & rsh) const
{
	return (this->x == rsh.getX() && this->y == rsh.getY());
}

bool	Point::operator!=( Point const &rsh) const
{
	return (this->x != rsh.getX() && this->y != rsh.getY());
}

/*-----------------------------------------------------------
                          Overload   DIVERS
-------------------------------------------------------------*/

std::ostream &operator<<(std::ostream & o, const Point & point)
{
    o << "(" << point.getX() << "," << point.getY() << ")";
    return o;
}