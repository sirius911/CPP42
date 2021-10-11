/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:01:12 by clorin            #+#    #+#             */
/*   Updated: 2021/09/30 11:01:36 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):
Form("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy):
Form(copy), _target(copy._target)
{
	if (this != &copy)
		*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm			&PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
	Form::operator=(copy);
	return *this;
}

/* ----------------------getter's------------------------------*/
std::string	const	&PresidentialPardonForm::getTarget(void)const
{
	return this->_target;
}

std::string 		PresidentialPardonForm::view() const
{
	std::string		str;

	str = Form::view();
	str.append("\twith target = ");
	str.append(C_CYAN + this->_target + C_RESET);
	return str;
}

/* --------------------  Methodes  ----------------------------*/
void			PresidentialPardonForm::execute(Bureaucrat const &b) const
{
	std::cout << C_YELLOW << this->_target << C_RESET << " was forgiven by "<<C_CYAN<<"Zafod Beeblebrox."<<C_RESET<<std::endl;
}

/*-------------------------------------------------------------
							OVERLOAD
---------------------------------------------------------------*/

std::ostream &	operator<<( std::ostream &o, PresidentialPardonForm const &src)
{
	o << src.view();
	return (o);
}