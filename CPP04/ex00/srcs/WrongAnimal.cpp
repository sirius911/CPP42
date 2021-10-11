/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:51:06 by clorin            #+#    #+#             */
/*   Updated: 2021/09/23 14:51:21 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*-----------------------------------------------------------------------------
								Canonique forms
------------------------------------------------------------------------------*/

WrongAnimal::WrongAnimal(void):_type(std::string())
{
	std::cout << "WrongAnimal's constructor by default called" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal's Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy) : _type(copy._type)
{
	std::cout << "WrongAnimal's constructor by copy called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &copy)
{
	if (this != &copy)
		this->_type = copy._type;
	std::cout << "WrongAnimal's assignation operator called" << std::endl;
	return *this;
}

/*-----------------------------------------------------------------------------
								GETTER
------------------------------------------------------------------------------*/

std::string		WrongAnimal::getType( void ) const
{
	return this->_type;
}

/*-----------------------------------------------------------------------------
								Methodes
------------------------------------------------------------------------------*/

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "...Sound of an unknown animal..." << std::endl;
}