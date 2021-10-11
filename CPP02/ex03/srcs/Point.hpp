/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:01:27 by clorin            #+#    #+#             */
/*   Updated: 2021/09/15 13:01:59 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const 	x;
		Fixed const		y;

	public:
		Point( void );							//canonical form
		Point( Point const &rsh);				//canonical form
		Point(Fixed const &, Fixed const &);
		virtual ~Point( void);					//canonical form

		Point & operator=( Point const &rhs);	//canonical form ?!?

		//setter 
		Fixed const	&getX( void ) const;
		Fixed const	&getY( void ) const;

		bool    operator==( Point const & ) const;
		bool	operator!=( Point const & ) const;
};

std::ostream &operator <<(std::ostream &, const Point &);

#endif
