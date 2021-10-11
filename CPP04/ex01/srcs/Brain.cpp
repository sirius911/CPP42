/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 09:21:32 by clorin            #+#    #+#             */
/*   Updated: 2021/09/24 09:22:00 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Brain's default constructor called" << std::endl;
}

Brain::~Brain( void )
{
	std::cout << "Brain's destructor called" << std::endl;
}

Brain::Brain(Brain const &copy)
{
	std::cout << "Brain's constructor by copy";
	*this = copy;
	std::cout << " called" << std::endl;
}

Brain	&Brain::operator=(Brain const & copy)
{
	std::cout << "Brain's operator= ";
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = copy._ideas[i];
	}
	std::cout << " called" << std::endl;
	return *this;
}

void		Brain::add(unsigned index, std::string ideas)
{
	if (index >= 100 )
		index = 99;
	this->_ideas[index] = ideas;
	std::cout << "Idea retained !!" << std::endl;
}

void	Brain::show(unsigned const index) const
{
	for (int i = 0; i < index; i++)
		std::cout << "Ideas # " << i << " : " << this->_ideas[i] << "(" << &_ideas[i]<< ")"<<std::endl;
}