/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:58:27 by clorin            #+#    #+#             */
/*   Updated: 2021/09/30 10:58:54 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target):
Form("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy):
Form(copy), _target(copy._target)
{
	if(this != &copy)
		*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	Form::operator=(copy);
	return *this;
}

/* ----------------------getter's------------------------------*/
std::string	const	&ShrubberyCreationForm::getTarget(void)const
{
	return this->_target;
}

std::string 		ShrubberyCreationForm::view() const
{
	std::string		str;

	str = Form::view();
	str.append("\twith target = ");
	str.append(C_CYAN + this->_target + C_RESET);
	return str;
}

/* --------------------  Methodes  ----------------------------*/
void			ShrubberyCreationForm::execute(Bureaucrat const &b) const
{
	std::string		file;
	file = this->_target + "_shrubbery";
	std::ofstream	fileStream(file.c_str());
	if (!fileStream)
	{
		std::cout << "Error creating file " << file << std::endl;
	}
	else
	{
		fileStream << "    *    " << std::endl;
		fileStream << "   ***   " << std::endl;
		fileStream << "  **o**  " << std::endl;
		fileStream << " *****o* " << std::endl;
		fileStream << "**o******" << std::endl;
		fileStream << "    |    " << std::endl;
	}
	fileStream.close();
}

/*-------------------------------------------------------------
							OVERLOAD
---------------------------------------------------------------*/

std::ostream &	operator<<( std::ostream &o, ShrubberyCreationForm const &src)
{
	std::string		view_base;

	view_base = src.view();
	o << view_base;
	return (o);
}