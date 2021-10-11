/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:22:43 by clorin            #+#    #+#             */
/*   Updated: 2021/09/23 15:22:45 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*-----------------------------------------------------------------------------
								Canonique forms
------------------------------------------------------------------------------*/

Dog::Dog( void ): Animal()
{
	this->_type = "Dog";
	std::cout << "\tDog's default constructor called" << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "\tDog's destructor called" << std::endl;
}

Dog::Dog(Dog const &copy): Animal(copy)
{
	std::cout << "\tDog's constructor by copy called" << std::endl;
}

Dog		&Dog::operator=(Dog const &copy)
{
	if ( this != &copy)
		this->_type = copy._type;
	std::cout << "\tDog's assignation operator called" << std::endl;
	return *this;
}

/*-----------------------------------------------------------------------------
								Methodes
------------------------------------------------------------------------------*/

void	Dog::makeSound( void ) const
{
	std::cout << "WHOUUFFF" << std::endl;
}