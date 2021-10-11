/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamonTrap.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 00:01:47 by clorin            #+#    #+#             */
/*   Updated: 2021/09/20 00:02:11 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamonTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

DiamonTrap::DiamonTrap(std::string const & name):
ClapTrap(name + "_clap_name"),
FragTrap(name),
ScavTrap(name)
{
	this->ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	//this->_hit_points = 100;	//FragTrap
	this->_energy_points = 50;	//ScavTrap
	//this->_attack_damage = 30;	//FragTrap
	std::cout << C_CYAN << "DiamonTrap constructor called <" << this->_name << ">" << C_RESET<< std::endl;
}

DiamonTrap::DiamonTrap( DiamonTrap const & rsh)
{
	*this = rsh;
	std::cout << C_CYAN << "DiamonTrap constructor by copy called <" << this->_name << ">" << C_RESET<< std::endl;
}
DiamonTrap::~DiamonTrap( void )
{
	std::cout << C_CYAN << "DiamonTrap destructor <" << this->_name << "> called" << C_RESET<<std::endl;
}

DiamonTrap & DiamonTrap::operator=(DiamonTrap const & rsh)
{
	if (this != &rsh)
	{
		this->_name = rsh._name;
		this->ClapTrap::_name = this->_name + "_clap_name";
		this->_hit_points = rsh._hit_points;
		this->_energy_points = rsh._energy_points;
		this->_attack_damage = rsh._attack_damage;
	}
	std::cout << C_CYAN << "DiamonTrap 'operator=' called" << C_RESET<<std::endl;
	return *this;
}

void			DiamonTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

void		DiamonTrap::whoAmi(void) const
{
	std::cout << C_CYAN<<"name = " << this->_name << " & ClapTrap::name = " << this->ClapTrap::_name << C_RESET<<std::endl;
}

/* 		To test
void		DiamonTrap::set(std::string s, int a, int b, int c)
{
	this->_name = s;
	this->_hit_points = a;
	this->_energy_points = b;
	this->_attack_damage = c;
}

void		DiamonTrap::affiche( void ) const
{
	std::cout << C_CYAN << "\tDiamonTrap " << C_RESET << "<" << this->_name << "> _hit_points = " << this->_hit_points << ", _energy_points = " << this->_energy_points << ", _attack_damage = " << this->_attack_damage << std::endl;

}
*/