/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:22:58 by clorin            #+#    #+#             */
/*   Updated: 2021/09/23 15:22:59 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


/*-----------------------------------------------------------------------------
								Canonique forms
------------------------------------------------------------------------------*/

WrongCat::WrongCat( void ): WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "\tWrongCat's default constructor called" << std::endl;
}

WrongCat::~WrongCat( void )
{
	std::cout << "\tWrongCat's destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy): WrongAnimal(copy)
{
	std::cout << "\tWrongCat's constructor by copy called" << std::endl;
}

WrongCat		&WrongCat::operator=(WrongCat const &copy)
{
	if ( this != &copy)
		this->_type = copy._type;
	std::cout << "\tWrongCat's assignation operator called" << std::endl;
	return *this;
}

/*-----------------------------------------------------------------------------
								Methodes
------------------------------------------------------------------------------*/

void	WrongCat::makeSound( void ) const
{
	std::cout << "MIAOUUUUUU ..." << std::endl;
}
