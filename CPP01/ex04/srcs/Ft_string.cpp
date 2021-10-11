/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ft_string.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 19:00:25 by clorin            #+#    #+#             */
/*   Updated: 2021/09/10 19:00:28 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ft_string.hpp"
#include <string>

Ft_string::Ft_string(std::string str): _string(str)
{
    return;
}

Ft_string::~Ft_string( void )
{
    return;
}

std::string    Ft_string::get( void ) const
{
    return this->_string;
}

void    Ft_string::add(char const c)
{
    this->_string += c;
}

void    Ft_string::add(std::string const s)
{
    this->_string += s;
}

int     Ft_string::replace(std::string const &s1, std::string const &s2)
{
    std::string dest("");
    std::size_t found = 0;
    std::size_t begin = 0;
    std::size_t end = 0;
    int         total=0;
    
    found = this->_string.find(s1, begin);
    while (found != std::string::npos)
    {
        end = found - begin;
        dest += this->_string.substr(begin, end);
        dest += s2;
        total++;
        begin = found + s1.size();
        found = this->_string.find(s1, begin);
    }
    end = found - begin;
    dest += this->_string.substr(begin, end);
    this->_string = dest;
    return (total);
}