/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:47:31 by clorin            #+#    #+#             */
/*   Updated: 2021/09/24 17:47:47 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include <iostream>
# include "Ice.hpp"

/*-----------------------------------------------------------------------------
								Canonique forms
------------------------------------------------------------------------------*/
Ice::Ice(): AMateria("ice")
{
}

Ice::~Ice( void )
{
}

Ice::Ice(Ice const &copy):AMateria()
{
	*this = copy;
}

Ice		&Ice::operator=(Ice const &copy)
{
	if (this != &copy)
		this->_type = copy._type;
	return *this;
}

/*-----------------------------------------------------------------------------
								Methodes
------------------------------------------------------------------------------*/

Ice*	Ice::clone( void ) const
{
	return new Ice();
}

void	Ice::use(ICharacter & target)
{
	std::cout << C_CYAN<<"* shoots an ice bolt at "<<C_YELLOW<< target.getName()<<C_CYAN << " *" <<C_RESET<< std::endl;
}