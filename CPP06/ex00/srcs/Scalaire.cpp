/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalaire.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:23:29 by clorin            #+#    #+#             */
/*   Updated: 2021/10/04 15:23:47 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Scalaire.hpp"
#include <stdlib.h>
#include <math.h>
#include <limits>
#include <cctype>

Scalaire::Scalaire()
{}

Scalaire::~Scalaire()
{}

Scalaire::Scalaire(std::string const &s): _value(s)
{
    Scalaire::parse();
}

Scalaire::Scalaire(Scalaire const &copy): _value(copy._value)
{}

Scalaire        &Scalaire::operator=(Scalaire const &copy)
{
    if (this!= &copy)
        this->_value = copy._value;
    return *this;
}

void            Scalaire::parse(void)
{
    char*   endptr;
    char    _c;

    if (this->_value.size() == 1)
    {
        _c = this->_value[0];
        this->_double = static_cast<double>(_c);
        if (_c >= '0' && _c <='9')
            this->_double -= 48; 
    }
    else if (this->_value.size() == 3 && this->_value[0] == '\'' && this->_value[2] == '\'')
    {
        _c = this->_value[1];
        this->_double = static_cast<double>(_c);
    }
    else
    {
        this->_double = std::strtod(this->_value.c_str(), &endptr);
        if (*endptr)
        {
            if (*endptr == 'f')
                endptr++;
            while (*endptr)
            {
                if (!isspace(*endptr))
                    throw Scalaire::NotConvertible();
                endptr++;
            }
        }
    }
}

void            Scalaire::print() const
{
    this->_toChar();
    this->_toInt();
    this->_toFloat();
    this->_toDouble();
}

void           Scalaire::_toFloat() const
{
    float _float = static_cast<float>(this->_double);

    std::cout << "float: " << _float;
    if (_float == floor(_float) && ! isinf(_float))
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f"<<std::endl;
}

void        Scalaire::_toDouble() const
{
    std::cout << "double: " << this->_double;
    if (this->_double == floor(this->_double) && !isinf(this->_double))
        std::cout << ".0";
    std::cout << std::endl;
}

void        Scalaire::_toInt() const
{
    std::cout << "int: ";
    if (this->_double >= INT_MAX)
        std::cout << " >= INT_MAX" << std::endl;
    else if (this->_double <= INT_MIN)
        std::cout << " <= INT_MIN" << std::endl;
    else if (isnan(this->_double))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(this->_double) << std::endl;
}

void        Scalaire::_toChar() const
{
    char    _char;

    std::cout << "char: ";
    _char = static_cast<char>(this->_double);
    if (this->_double >= 32 && this->_double <= 126)
        std::cout << _char << std::endl;
    else if (isnan(this->_double))
        std::cout << "impossible" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;    
}

const char      *Scalaire::NotConvertible::what() const throw()
{
    return ("not Convertible");
}