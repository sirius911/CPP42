/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:32:16 by clorin            #+#    #+#             */
/*   Updated: 2021/09/10 15:32:29 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include "Ft_string.hpp"
#include <string>
#include <fstream>
#include <iostream>

Replace::Replace(std::string const & fileName, std::string const & s1, std::string const & s2)
:
    _fileName(fileName), _s1(s1), _s2(s2), _string("")
    {
        return;
    }
Replace::~Replace( void )
{

}

bool    Replace::_valid( void ) const
{
    if (this->_s1.empty()|| this->_s2.empty())
    {
        std::cout << "Error: s1 and s2 must be NOT empty" << std::endl;
        return false;
    }
    return true;
}

bool    Replace::_load( void )
{
    std::ifstream   file(this->_fileName);
    std::string     line;

    if (file.is_open())
    {
        while(std::getline (file, line))
        {
            this->_string.add(line);
            this->_string.add('\n');
        }
        file.close();
        return true;
    }
    std::cout << "Error: unable to load '" << this->_fileName << "'" << std::endl;
    return false;
}

bool    Replace::_write() const
{
    std::ofstream   file(this->_fileName + ".replace");
    if (file.is_open())
    {
        file << this->_string.get();
        file.close();
        return true;
    }
    std::cout << "Error:unable to write in '" << this->_fileName << ".replace'" << std::endl;
    return false;
}

int    Replace::go( void )
{
    if (!this->_valid() || !this->_load())
        return (1);
    
    this->_string.replace(this->_s1, this->_s2);

    return (this->_write() == false);
}