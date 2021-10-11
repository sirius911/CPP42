/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:01:41 by clorin            #+#    #+#             */
/*   Updated: 2021/09/27 12:01:58 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character():_name("Default_Name")
{
	for(size_t i = 0; i < MAX_INV; i++)
		this->_inventory[i] = 0;
}

Character::~Character()
{
	for (size_t i = 0; i < MAX_INV; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

Character::Character(Character const &copy): _name(copy._name+"_cpy")
{
	std::cout << "Character's constructor by Copy of "<< copy.getName() <<" called"<< std::endl;
	for(size_t  i = 0; i < MAX_INV; i++)
	{
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
		else
			this->_inventory[i] = 0;
		std::cout << "\tcopy["<<i<<"] ("<< &copy._inventory[i]<<") => ("<<&this->_inventory[i]<<")"<<std::endl;
	}
	std::cout << "------------------------------------------" << std::endl;
}

Character::Character(std::string const &name): _name(name)
{
	//std::cout << "create Character "<<this->_name<<std::endl;
	for(size_t i = 0; i < MAX_INV; i++)
	{
		this->_inventory[i] = 0;
		//std::cout << "\t_inventory["<<i<<"] in ("<< &this->_inventory[i]<<")"<<std::endl;
	}
}

Character			&Character::operator=(Character const &copy)
{
	std::cout << "Copy of "<< copy._name << std::endl;
	if (this != &copy)
	{
		for(size_t i = 0; i < MAX_INV; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (copy._inventory[i])
				this->_inventory[i] = copy._inventory[i]->clone();
			else
				this->_inventory[i] = 0;
			std::cout << "\t_inventory["<<i<<"] in "<< &this->_inventory[i]<<std::endl;
		}
	}
	return *this;
}

std::string const	&Character::getName(void) const
{
	return this->_name;
}

void				Character::equip(AMateria *m)
{
	for(size_t i = 0; i < MAX_INV; i++)
	{
		if (this->_inventory[i] == 0)
		{
			this->_inventory[i] = m;
			return;
		}
	}
}

void				Character::unequip(int idx)
{
	if (idx >= 0 && idx < MAX_INV && this->_inventory[idx])
		this->_inventory[idx] = 0;		// we don't delete the Materia
}

void				Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < MAX_INV && this->_inventory[idx])
		this->_inventory[idx]->use(target);
}