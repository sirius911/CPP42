/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:42:01 by clorin            #+#    #+#             */
/*   Updated: 2021/09/24 17:42:18 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < MAX_MEM; i++)
		this->_memory[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
	std::cout << "**** MateriaSource's Constructor by Copy :"<<std::endl;
	for (size_t i = 0; i < MAX_MEM; i++)
	{
		if (copy._memory[i])
			this->_memory[i] = copy._memory[i]->clone();
		else
			this->_memory[i] = 0;
		std::cout << "\tcopy["<<i<<"] ("<< &copy._memory[i]<<") => ("<<&this->_memory[i]<<")"<<std::endl;
	}
	std::cout << "------------------------------------------" << std::endl;
}
	
MateriaSource::~MateriaSource()
{
	for(size_t i = 0; i < MAX_MEM; i++)
		if ( this->_memory[i])
			delete this->_memory[i];
}
	
MateriaSource	&MateriaSource::operator=(MateriaSource const &copy)
{
	std::cout << "Operator '=' of MateriaSource";
	if (this != &copy)
	{
		for (size_t i = 0; i < MAX_MEM; i++)
		{
			if (this->_memory[i])
				delete this->_memory[i];
			if (copy._memory[i])
				this->_memory[i] = copy._memory[i]->clone();
			else
				this->_memory[i] = 0;
		}
	}
	std::cout << " called" << std::endl;
	return *this;
}
	
void MateriaSource::learnMateria(AMateria* m)
{
	for (size_t i = 0; i < MAX_MEM; i++)
	{
		if (this->_memory[i] == 0)
		{
			this->_memory[i] = m;
			return;
		}
	}
	std::cout << "Source full of Materia" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0 ; i < MAX_MEM; i++)
	{
		if (this->_memory[i] && this->_memory[i]->getType() == type)
			return this->_memory[i]->clone();
	}
	return 0;
}