/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 22:41:17 by clorin            #+#    #+#             */
/*   Updated: 2021/09/19 22:41:32 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

/*-----------------------------------------------------------------------------
							CONSTRUCTORS / DESTRUCTOR
------------------------------------------------------------------------------*/

ScavTrap::ScavTrap(std::string const & name): 	ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << C_GREEN << "ScavTrap constructor called <" << this->_name << ">" << C_RESET << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const & rsh)
{
	*this = rsh;
	std::cout << C_GREEN << "ScavTrap contructor by copy" << C_RESET << std::endl;
	return;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << C_GREEN << "Destructor of ScavTrap <" << this->_name << "> called" << C_RESET <<std::endl;
	return;
}

/*---------------------------------------------------------------------------
								Operators
-----------------------------------------------------------------------------*/

ScavTrap		&ScavTrap::operator=(ScavTrap const &rsh)
{
	if (this != &rsh)
		ClapTrap::operator=(rsh);
	return *this;
}

void			ScavTrap::guardGate( void ) const
{
	std::cout << C_GREEN << "ScavTrap <" << this->_name << "> in Gate keeper mode" << C_RESET << std::endl;
}

/*****************************************************************************/

void			ScavTrap::attack(std::string const & target)
{
	if (this->_energy_points >= 1)
	{
		std::cout << C_GREEN << "ScavTrap " << C_RESET << this->_name << C_GREEN << " attack " << C_RESET << target << ", causing " << this->_attack_damage << " points of damage" << std::endl;
		this->_energy_points--;
		std::cout << "\t" << this->_name << ": energy_points = " << this->_energy_points << std::endl;
	}
	else 
		std::cout << C_GREEN << "ScavTrap " << this->_name << " not enought energy points to attack" << std::endl;
}
