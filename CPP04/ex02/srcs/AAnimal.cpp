/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:51:06 by clorin            #+#    #+#             */
/*   Updated: 2021/09/23 14:51:21 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*-----------------------------------------------------------------------------
								Canonique forms
------------------------------------------------------------------------------*/

AAnimal::AAnimal(void):_type(std::string()), _nbIdeas(0)
{
	std::cout << "Abstract Animal's constructor by default called" << std::endl;
}

AAnimal::~AAnimal( void )
{
	std::cout << "Abstract Animal's Destructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &copy) : _type(copy._type), _nbIdeas(copy._nbIdeas)
{
	std::cout << "Abstract Animal's constructor by copy called" << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal const &copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
		this->_nbIdeas = copy._nbIdeas;
	}
	std::cout << "Abstract Animal's assignation operator called" << std::endl;
	return *this;
}

/*-----------------------------------------------------------------------------
								GETTER
------------------------------------------------------------------------------*/

std::string		AAnimal::getType( void ) const
{
	return this->_type;
}

/*-----------------------------------------------------------------------------
								Methodes
------------------------------------------------------------------------------*/
