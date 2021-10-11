/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:57:08 by clorin            #+#    #+#             */
/*   Updated: 2021/10/01 10:57:34 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{

}

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

Intern::~Intern()
{

}

Intern		&Intern::operator=(Intern const &copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

Form*		Intern::createShrubbery(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

Form*		Intern::createRobotomy(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

Form*		Intern::createPresidential(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

Form*		Intern::makeForm(std::string const &name, std::string const &target)
{
	Form*	dest;
	size_t	i = 0;

	while(i < NB_FORM)
	{
		if (name == Intern::select_function[i].name_form)
		{	
			dest = (this->*(select_function[i].function_create_Form))(target);
			std::cout << "Intern creats <" << C_CYAN << dest->getName() << C_RESET << ">"<<std::endl;
			return (dest);
		}
		i++;
	}
	std::cout << "Intern " << C_RED << "cannot found " <<C_RESET<< "the Form <" << C_CYAN << name << C_RESET << "> !"<<std::endl;
	return 0;
}

const		Intern::t_Form	Intern::select_function[NB_FORM] = {
		{ "shrubbery", &Intern::createShrubbery},
		{ "robotomy", &Intern::createRobotomy},
		{ "presidential", &Intern::createPresidential}
};
