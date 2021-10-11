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

    private:
        int                 _value;
        const static int    _nb_bits = 8;
};

std::ostream &operator <<(std::ostream &, const Fixed &);

#endif