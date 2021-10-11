/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:41:21 by clorin            #+#    #+#             */
/*   Updated: 2021/09/04 17:18:12 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "Contact.class.hpp"

Contact::Contact(void) : _is_empty(true)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

bool		Contact::is_empty(void) const
{
	return (this->_is_empty);
}

std::string	Contact::getFirst_name(void) const
{
	return (this->_first_name);
}

std::string	Contact::getLast_name(void) const
{
	return (this->_last_name);
}

std::string	Contact::getNickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::getPhone_number(void) const
{
	return (this->_phone_number);
}

std::string	Contact::getDarkest_secret(void) const
{
	return (this->_darkest_secret);
}

bool	Contact::input(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5)
{
	this->_first_name = s1;
	this->_last_name = s2;
	this->_nickname = s3;
	this->_phone_number = s4;
	this->_darkest_secret = s5;
	this->_is_empty = false;
	return (true);
}

void	Contact::print(void)
{
	std::cout << "\033[33mfirst name     : \033[34m" << this->_first_name << "\033[0m" <<std::endl;
	std::cout << "\033[33mlast name      : \033[34m" << this->_last_name << "\033[0m" <<std::endl; 
	std::cout << "\033[33mnickname       : \033[34m" << this->_nickname << "\033[0m" <<std::endl;
	std::cout << "\033[33mphone number   : \033[34m" << this->_phone_number << "\033[0m" <<std::endl;
	std::cout << "\033[33mdarkest secret : \033[34m" << this->_darkest_secret << "\033[0m" <<std::endl;
}
