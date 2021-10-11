/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:35:58 by clorin            #+#    #+#             */
/*   Updated: 2021/09/11 18:36:34 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class   Fixed
{
    public:
        Fixed( void );
        Fixed( Fixed const & src);
        Fixed( int const i);
        Fixed( float const f);
        virtual ~Fixed( void );
        
        Fixed & operator=( Fixed const & rhs);
        int     getRawBits( void ) const;
        void    setRawBits(int const raw);
        int     toInt(void) const;
        float   toFloat(void) const;

        Fixed   operator+( Fixed const & ) const;
        Fixed   operator-( Fixed const &) const;
        Fixed   operator*( Fixed const &) const;
        Fixed   operator/( Fixed const &) const;

        bool    operator==( Fixed const & ) const;
        bool    operator!=( Fixed const & ) const;

        bool    operator>( Fixed const &) const;
        bool    operator>=( Fixed const & rsh) const;
        bool    operator<( Fixed const & rsh) const;
        bool    operator<=( Fixed const & rsh) const;

        Fixed   operator++( int );      // postfix increment
        Fixed   &operator++( void );    // prefix increment
        Fixed   operator--( int );      // postfix decrement
        Fixed   &operator--( void );    // prefix decrement

        static const Fixed  &max(Fixed const &, Fixed const &);
        static Fixed        &max(Fixed &, Fixed &);

        static const Fixed  &min(Fixed const &, Fixed const &);
        static Fixed        &min(Fixed &, Fixed &);

    private:
        int                 _value;
        const static int    _nb_bits = 8;
};

std::ostream &operator <<(std::ostream &, const Fixed &);
Fixed           &max(Fixed &, Fixed &);
const Fixed     &max(Fixed const &, Fixed const &);
Fixed           &min(Fixed &, Fixed &);
const Fixed     &min(Fixed const &, Fixed const &);

#endif