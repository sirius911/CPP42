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

class   Fixed
{
    public:
        Fixed( void );
        Fixed( Fixed const & src);
        virtual ~Fixed( void );
        
        Fixed & operator=( Fixed const & rhs);
        int     getRawBits( void ) const;
        void    setRawBits(int const raw);

    private:
        int                 _value;
        static  const int   _nb_bits = 8;
};
#endif
