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

Cat::Cat( void ): AAnimal()
{
	this->_type = "Cat";
	std::cout << "\tCat's default constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::~Cat( void )
{
	std::cout << "\tCat's destructor called" << std::endl;
	delete this->_brain;
}

Cat::Cat(Cat const &copy): AAnimal(), _brain( new Brain())
{
	std::cout << "\tCat's constructor by copy called" << std::endl;
	*this = copy;
}

Cat		&Cat::operator=(Cat const &copy)
{
	if ( this != &copy)
	{
		this->_type = copy._type;
		this->_nbIdeas = copy._nbIdeas;
		*this->_brain = *copy._brain;
	}
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

void	Cat::add_ideas(std::string const ideas)
{
	std::cout << "We add the idea '" << ideas << "' in position " << this->_nbIdeas << " ... ";
	this->_brain->add(this->_nbIdeas, ideas);
	this->_nbIdeas++;
	if (_nbIdeas >= 100)
		this->_nbIdeas = 99;
}

void	Cat::show_ideas( void ) const
{
	this->_brain->show(this->_nbIdeas);
}