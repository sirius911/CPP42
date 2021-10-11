/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:56:43 by clorin            #+#    #+#             */
/*   Updated: 2021/09/27 11:05:59 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const &type):_type(type)
{
}

AMateria::AMateria(AMateria const &copy):_type(copy._type)
{
}

AMateria::~AMateria()
{
}

AMateria		&AMateria::operator=(AMateria const &copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return *this;
}

std::string const&	AMateria::getType(void) const
{
	return this->_type;
}

void			AMateria::use(ICharacter &target)
{

}
