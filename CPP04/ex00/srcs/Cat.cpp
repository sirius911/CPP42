/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:22:58 by clorin            #+#    #+#             */
/*   Updated: 2021/09/23 15:22:59 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


/*-----------------------------------------------------------------------------
								Canonique forms
------------------------------------------------------------------------------*/

Cat::Cat( void ): Animal()
{
	this->_type = "Cat";
	std::cout << "\tCat's default constructor called" << std::endl;
}

Cat::~Cat( void )
{
	std::cout << "\tCat's destructor called" << std::endl;
}

Cat::Cat(Cat const &copy): Animal(copy)
{
	std::cout << "\tCat's constructor by copy called" << std::endl;
}

Cat		&Cat::operator=(Cat const &copy)
{
	if ( this != &copy)
		this->_type = copy._type;
	std::cout << "\tCat's assignation operator called" << std::endl;
	return *this;
}

/*-----------------------------------------------------------------------------
								Methodes
------------------------------------------------------------------------------*/

void	Cat::makeSound( void ) const
{
	std::cout << "MIAOUUUUUU ..." << std::endl;
}
