/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:50:26 by clorin            #+#    #+#             */
/*   Updated: 2021/09/10 13:51:02 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string const name, Weapon & weapon) : _name(name), _weapon(weapon)
{
    return;
}

HumanA::~HumanA( void )
{
    return;
}

void    HumanA::attack( void ) const
{
    std::cout << this->_name << " attacks with his " << this->_weapon.getType()<< std::endl;
}