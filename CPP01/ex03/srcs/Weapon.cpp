/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:48:10 by clorin            #+#    #+#             */
/*   Updated: 2021/09/09 11:48:29 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"

Weapon::Weapon( void ) : _type(std::string())
{
	return;
}

Weapon::Weapon(std::string type) : _type(type)
{
	return;
}

Weapon::~Weapon( void )
{
	return;
}

void				Weapon::setType(std::string type)
{
	this->_type = type;
}

std::string const &	Weapon::getType( void ) const
{
	return (this->_type);
}