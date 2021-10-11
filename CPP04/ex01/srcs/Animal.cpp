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

Animal::Animal(void):_type(std::string()), _nbIdeas(0)
{
	std::cout << "Animal's constructor by default called" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Animal's Destructor called" << std::endl;
}

Animal::Animal(Animal const &copy) : _type(copy._type), _nbIdeas(copy._nbIdeas)
{
	std::cout << "Animal's constructor by copy called" << std::endl;
}

Animal	&Animal::operator=(Animal const &copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
		this->_nbIdeas = copy._nbIdeas;
	}
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

void	Animal::add_ideas(std::string const ideas)
{
	// In future exercises this function will be pure (= 0)
	//and therefore will not need to be implemented
}
void	Animal::show_ideas( void ) const
{
		// In future exercises this function will be pure (= 0)
		//and therefore will not need to be implemented
}