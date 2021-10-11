/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:51:06 by clorin            #+#    #+#             */
/*   Updated: 2021/09/23 14:51:21 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*-----------------------------------------------------------------------------
								Canonique forms
------------------------------------------------------------------------------*/

Animal::Animal(void):_type(std::string())
{
	std::cout << "Animal's constructor by default called" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Animal's Destructor called" << std::endl;
}

Animal::Animal(Animal const &copy) : _type(copy._type)
{
	std::cout << "Animal's constructor by copy called" << std::endl;
}

Animal	&Animal::operator=(Animal const &copy)
{
	if (this != &copy)
		this->_type = copy._type;
	std::cout << "Animal's assignation operator called" << std::endl;
	return *this;
}

/*-----------------------------------------------------------------------------
								GETTER
------------------------------------------------------------------------------*/

std::string		Animal::getType( void ) const
{
	return this->_type;
}

/*-----------------------------------------------------------------------------
								Methodes
------------------------------------------------------------------------------*/

void	Animal::makeSound( void ) const
{
	std::cout << "...Sound of an unknown animal..." << std::endl;
}