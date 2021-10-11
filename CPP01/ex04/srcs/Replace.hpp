/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:27:44 by clorin            #+#    #+#             */
/*   Updated: 2021/09/10 15:28:11 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <string>
#include <fstream>
#include "Ft_string.hpp"

class   Replace
{
    private:
        std::string const   & _fileName;
        Ft_string           _string;
        std::string const   & _s1;
        std::string const   & _s2;

        bool                _valid( void ) const;
        bool                _load( void );
        bool                _write( void ) const;

    public:
        Replace(std::string const &, std::string const &, std::string const &);
        ~Replace( void );

        int            go( void );
};

#endif
