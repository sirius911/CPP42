/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:51:37 by clorin            #+#    #+#             */
/*   Updated: 2021/09/10 14:51:42 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string const name) : _name(name), _weapon(NULL)
{
    return;
}

HumanB::~HumanB( void )
{
    return;
}

void    HumanB::setWeapon(Weapon & weapon)
{
    this->_weapon = &weapon;
}

void    HumanB::attack( void ) const
{
    std::cout << this->_name << " attacks with his " << this->_weapon->getType()<< std::endl;
}
