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

Dog::Dog( void ): AAnimal()
{
	this->_type = "Dog";
	std::cout << "\tDog's default constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::~Dog( void )
{
	std::cout << "\tDog's destructor called" << std::endl;
	delete this->_brain;
}

Dog::Dog(Dog const &copy): AAnimal(), _brain(new Brain())
{
	std::cout << "\tDog's constructor by copy called" << std::endl;
	*this = copy;
}

Dog		&Dog::operator=(Dog const &copy)
{
	if ( this != &copy)
	{
		this->_type = copy._type;
		this->_nbIdeas = copy._nbIdeas;
		*this->_brain = *copy._brain;
	}
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

void	Dog::add_ideas(std::string const ideas)
{
	std::cout << "We add the idea '" << ideas << "' in position " << this->_nbIdeas << " ... ";
	this->_brain->add(this->_nbIdeas, ideas);
	this->_nbIdeas++;
	if (_nbIdeas >= 100)
		this->_nbIdeas = 99;
}

void	Dog::show_ideas( void ) const
{
	this->_brain->show(this->_nbIdeas);
}