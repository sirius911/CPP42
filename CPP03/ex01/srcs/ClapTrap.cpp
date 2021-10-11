/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:59:08 by clorin            #+#    #+#             */
/*   Updated: 2021/09/19 19:59:23 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/*-----------------------------------------------------------------------------
							CONSTRUCTORS / DESTRUCTOR
------------------------------------------------------------------------------*/
ClapTrap::ClapTrap(std::string const & name):
_name(name),
_hit_points(10),
_energy_points(10),
_attack_damage(0)
{
	std::cout << C_RED << "Constructor called for ClapTrap(" << name << ")" << C_RESET << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const & rsh): 
_name(rsh._name),
_hit_points(rsh._hit_points),
_energy_points(rsh._energy_points),
_attack_damage(rsh._attack_damage)
{
	std::cout << C_RED <<"Constructor by copy called" << C_RESET << std::endl;
	return ;
}

/*****************************************************************************/

ClapTrap::~ClapTrap( void )
{
	std::cout << C_RED << "Destructor of ClapTrap <" << this->_name << "> called" << C_RESET << std::endl;
	return;
}

void			ClapTrap::attack(std::string const & target)
{
	if (this->_energy_points >= 1)
	{
		std::cout << C_RED <<"ClapTrap " <<C_RESET << this->_name << C_RED << " attack " << C_RESET << target << ", causing " << this->_attack_damage << " points of damage" << std::endl;
		this->_energy_points--;
		std::cout << "\t"<< this->_name << ": energy_points = " << this->_energy_points << std::endl;
	}
	else 
		std::cout << C_RED <<"ClapTrap " <<C_RESET<< this->_name << " not enought energy points to attack" << std::endl;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points <= amount)
		this->_hit_points = 0;
	else
		this->_hit_points -= amount;
	std::cout << C_RED <<"ClapTrap " << C_RESET << this->_name << " takes " << amount << " points of damage" << std::endl;
	std::cout << "\t" <<this->_name <<": hit_points = " << this->_hit_points;
	if (this->_hit_points == 0)
		std::cout << " -> I am dead";
	std::cout << std::endl;
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	this->_hit_points += amount;
	std::cout << C_RED <<"ClapTrap <" <<C_RESET<< this->_name << "> repaired with " << amount << " points" << std::endl;
	std::cout << "\t"<<this->_name <<": hit_points = " << this->_hit_points << std::endl;
}

/*---------------------------------------------------------------
					Operators
-----------------------------------------------------------------*/
ClapTrap		&ClapTrap::operator=(ClapTrap const & rsh)
{
	std::cout << C_RED << "Assignation with 'operator=' called" << C_RESET <<std::endl;
	if (this != &rsh)
	{
		this->_name = rsh._name;
		this->_hit_points = rsh._hit_points;
		this->_energy_points = rsh._energy_points;
		this->_attack_damage = rsh._attack_damage;
	}
	return *this;
}
