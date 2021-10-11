/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:59:57 by clorin            #+#    #+#             */
/*   Updated: 2021/09/30 11:00:22 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):
Form("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy):
Form(copy), _target(copy._target)
{
	if (this != &copy)
		*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm		&RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
	Form::operator=(copy);
	return *this;
}

/* ----------------------getter's------------------------------*/
std::string	const	&RobotomyRequestForm::getTarget(void)const
{
	return this->_target;
}

std::string 		RobotomyRequestForm::view() const
{
	std::string		str;

	str = Form::view();
	str.append("\twith target = ");
	str.append(C_CYAN + this->_target + C_RESET);
	return str;
}

/* --------------------  Methodes  ----------------------------*/
void			RobotomyRequestForm::execute(Bureaucrat const &b) const
{
	std::cout << C_CYAN;
 std::cout << "__      ___ __ ___   ___  _ __ ___  _ __ ___  " << std::endl;
 std::cout << "\\ \\ /\\ / / '__/ _ \\ / _ \\| '_ ` _ \\| '_ ` _ \\ " << std::endl;
 std::cout << "\\ V  V /| | | (_) | (_) | | | | | | | | | | |" << std::endl;
 std::cout << "  \\_/\\_/ |_|  \\___/ \\___/|_| |_| |_|_| |_| |_|" << C_RESET <<std::endl;
 if (rand() % 2)
 	std::cout << C_YELLOW << this->_target << C_RESET << " has been " <<
 C_CYAN << "Robotomyzed successfully" << C_RESET << std::endl;
 else
 	std::cout << C_RED << "Ouch !! "<< C_RESET << "A bolt popped, damn "<< 
 C_YELLOW << "Bob" << C_RESET<< "'s robotomysation didn't work, sorry" << std::endl;
}

/*-------------------------------------------------------------
							OVERLOAD
---------------------------------------------------------------*/

std::ostream &	operator<<( std::ostream &o, RobotomyRequestForm const &src)
{
	o << src.view();
	return (o);
}