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

/* --------------------------------------------------------
                        Constructors
------------------------------------------------------------*/
Fixed::Fixed( void ) : _value(0)
{
    //std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed( Fixed const & src ) 
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return;
}

Fixed::Fixed( int const i )
{
    //std::cout << "Int constructor called" << std::endl;
    this->_value = (int) i << Fixed::_nb_bits;
}

Fixed::Fixed( float const f )
{
    //std::cout << "Float constructor called" << std::endl;
    this->_value = (int) (roundf(f * (1 << Fixed::_nb_bits)));
}

/*----------------------------------------------------------
                        Destructor
-------------------------------------------------------------*/
Fixed::~Fixed( void )
{
    //std::cout << "Destructor called" << std::endl;
    return;
}

/* -----------------------------------------------------------
        Getter Setter and Assignation operator
--------------------------------------------------------------*/

Fixed   & Fixed::operator=(Fixed const& rhs)
{
    //std::cout << "Assignation operator called" << std::endl;
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

/*--------------------------------------------------------------
                                Cast
----------------------------------------------------------------*/
int     Fixed::toInt( void ) const
{
    return (int)this->_value >> Fixed::_nb_bits;
}

float   Fixed::toFloat( void ) const
{
     return (float) (this->_value) / (float)(1 << Fixed::_nb_bits);
}

/*---------------------------------------------------------
                        Operateurs + - * /
----------------------------------------------------------*/
Fixed   Fixed::operator+( Fixed const & rsh) const
{
    Fixed   dest;
    dest.setRawBits(this->_value + rsh.getRawBits());
    return dest;
}

Fixed   Fixed::operator-( Fixed const & rsh) const
{
    Fixed   dest;
    dest.setRawBits(this->_value - rsh.getRawBits());
    return dest;
}

Fixed   Fixed::operator*( Fixed const & rsh) const
{   
    Fixed   dest;
    dest.setRawBits((this->_value * rsh.getRawBits()) >> Fixed::_nb_bits);
    return dest;
}

Fixed   Fixed::operator/( Fixed const & rsh) const
{
    Fixed   dest;
    dest.setRawBits((this->_value << Fixed::_nb_bits) / rsh.getRawBits());
    return dest;
}

/* -----------------------------------------------
                    comparaison
-------------------------------------------------*/
bool    Fixed::operator==( Fixed const & rsh) const
{
    return (this->_value == rsh.getRawBits());
}

bool    Fixed::operator!=( Fixed const & rsh) const
{
    return (!(this->_value == rsh.getRawBits()));
}

bool    Fixed::operator>( Fixed const & rsh) const
{
    return (this->_value > rsh.getRawBits());
}

bool    Fixed::operator>=( Fixed const & rsh) const
{
    return (this->_value >= rsh.getRawBits());
}

bool    Fixed::operator<( Fixed const & rsh) const
{
    return (this->_value < rsh.getRawBits());
}
bool    Fixed::operator<=( Fixed const & rsh) const
{
    return (this->_value <= rsh.getRawBits());
}

/* ----------------------------------------------------
                increment and decrement
-----------------------------------------------------*/

Fixed   Fixed::operator++(int)  //postfix increment
{
    Fixed   old = *this;    //copy old Fixed
    this->operator++();           //prefix increment
    return old;            // return old value;
}

Fixed   &Fixed::operator++( void )  //prefix increment
{
    this->_value++;
    return (*this);
}

Fixed   Fixed::operator--(int)  //postfix decrement
{
    Fixed   old = *this;
    this->operator--();
    return old;
}

Fixed   &Fixed::operator--( void )  //prefix decrement
{
    this->_value--;
    return (*this);
}

/*----------------------------------------------------------
                        MAX and Min
-----------------------------------------------------------*/

const Fixed     &Fixed::max(Fixed const &f1, Fixed const &f2)
{
    if (f1 > f2)
        return f1;
    return f2;
}

Fixed           &Fixed::max(Fixed &f1, Fixed &f2)
{
    if (f1 > f2)
        return f1;
    return f2;
}

const Fixed     &Fixed::min(Fixed const &f1, Fixed const &f2)
{
    if (f1 < f2)
        return f1;
    return f2;
}

Fixed           &Fixed::min(Fixed &f1, Fixed &f2)
{
    if (f1 < f2)
        return f1;
    return f2; 
}

/*-----------------------------------------------------------
                          Overload   DIVERS
-------------------------------------------------------------*/

std::ostream &operator<<(std::ostream & o, const Fixed & fixed)
{
    o << fixed.toFloat();
    return o;
}

Fixed       &max(Fixed &f1, Fixed &f2)
{
    if (f1 > f2)
        return f1;
    return f2;
}

const Fixed &max(Fixed const &f1, Fixed const &f2)
{
    if (f1 > f2)
        return f1;
    return f2;    
}

Fixed       &min(Fixed &f1, Fixed &f2)
{
 if (f1 < f2)
        return f1;
    return f2;
}

const Fixed &min(Fixed const &f1, Fixed const &f2)
{
    if (f1 < f2)
        return f1;
    return f2;
}