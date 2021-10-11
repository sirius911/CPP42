/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:36:42 by clorin            #+#    #+#             */
/*   Updated: 2021/09/11 18:36:52 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed( void ) : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed( Fixed const & src ) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return;
}

Fixed::Fixed( int const i )
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = (int) i << Fixed::_nb_bits;
}

Fixed::Fixed( float const f )
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = (int) (roundf(f * (1 << Fixed::_nb_bits)));
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
    return;
}

Fixed   & Fixed::operator=(Fixed const& rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

int     Fixed::getRawBits( void ) const
{
    return this->_value;
}

void    Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

int     Fixed::toInt( void ) const
{
    return (int)this->_value >> Fixed::_nb_bits;
}

float   Fixed::toFloat( void ) const
{
     return (float) (this->_value) / (float)(1 << Fixed::_nb_bits);
}

std::ostream &operator<<(std::ostream & o, const Fixed & fixed)
{
    o << fixed.toFloat();
    return o;
}