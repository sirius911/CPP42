/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:47:31 by clorin            #+#    #+#             */
/*   Updated: 2021/09/27 12:29:00 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include <iostream>
# include "Cure.hpp"

/*-----------------------------------------------------------------------------
								Canonique forms
------------------------------------------------------------------------------*/
Cure::Cure(): AMateria("cure")
{
}

Cure::~Cure( void )
{
}

Cure::Cure(Cure const &copy):AMateria()
{
	*this = copy;
}

Cure		&Cure::operator=(Cure const &copy)
{
	if (this != &copy)
		this->_type = copy._type;
	return *this;
}

/*-----------------------------------------------------------------------------
								Methodes
------------------------------------------------------------------------------*/

Cure*	Cure::clone( void ) const
{
	return new Cure();
}

void	Cure::use(ICharacter & target)
{
	std::cout << C_GREEN << "* heals "<<C_YELLOW << target.getName()<<C_GREEN << "'s wounds *"<<C_RESET << std::endl;
}
