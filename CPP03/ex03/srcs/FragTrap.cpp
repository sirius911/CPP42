/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:45:26 by clorin            #+#    #+#             */
/*   Updated: 2021/09/19 23:45:40 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string const & name): 	ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << C_YELLOW << "FragTrap constructor called with name <" << this->_name << ">" <<C_RESET<< std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const & rsh)
{
	*this = rsh;
	std::cout << C_YELLOW<<"FragTrap contructor by copy" << C_RESET <<std::endl;
	return;
}

FragTrap::~FragTrap( void )
{
	std::cout << C_YELLOW<<"Destructor of FragTrap <" << this->_name << "> called" <<C_RESET<< std::endl;
	return;
}

FragTrap		&FragTrap::operator=(FragTrap const &rsh)
{
	if (this != &rsh)
		ClapTrap::operator=(rsh);
	return *this;
}

void			FragTrap::highFivesGuys( void ) const
{
	std::cout <<C_YELLOW<< "FragTrap<"<<this->_name<<"> : High Fives Guys !" << C_RESET<<std::endl;
}