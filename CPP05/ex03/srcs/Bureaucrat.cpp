/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:11:10 by clorin            #+#    #+#             */
/*   Updated: 2021/09/28 14:11:28 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, unsigned int grade): _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy): _name(copy._name)
{
	if (copy._grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (copy._grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = copy._grade;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat const		&Bureaucrat::operator=(Bureaucrat const &copy)
{
	if (this != &copy)
	{	
		if (copy._grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (copy._grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade = copy._grade;
	}
	return *this;
}

/*--------------------------- Getter's -------------------------------------*/

unsigned int			Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::string				Bureaucrat::getName() const
{
	return this->_name;
}

/* ---------------------------  Functions  ---------------------------------*/

void					Bureaucrat::incrementGrade()
{
	if(this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	std::cout << C_YELLOW << this->_name << C_RESET <<" upgraded level "<< C_GREEN << this->_grade << C_RESET << std::endl;
}

void					Bureaucrat::decrementGrade()
{
	if(this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	std::cout << C_YELLOW << this->_name << C_RESET <<" decreased level " <<C_GREEN << this->_grade << C_RESET <<std::endl;
}

void					Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << C_YELLOW << this->_name << C_RESET << " signs " << C_GREEN << form.getName() << C_RESET << std::endl;
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cout << C_YELLOW << this->_name << C_RED << " cannot sign because his signing level is too low"<<C_RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << C_YELLOW << this->_name << C_RESET << " cannot sign because " << C_RED << e.what() << C_RESET << std::endl;
	}
}

void					Bureaucrat::executeForm(Form const &form) const
{
	try
	{
		form.is_executable(*this);		//if not executable => exception
		std::cout << C_YELLOW << this->_name << C_GREEN<< " executs " << C_CYAN<< form.getName()<<C_RESET<<std::endl;
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << C_YELLOW << this->_name << C_RESET << " cannot execute because: " << C_RED << e.what() << C_RESET << std::endl;
	}
}

/*-------------------------------------------------------------
							EXCEPTIONS
---------------------------------------------------------------*/
const char*				Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception: The grade must be >= 1");	
}

const char*				Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception: The grade must be <= 150");
}

/*-------------------------------------------------------------
							OVERLOAD
---------------------------------------------------------------*/

std::ostream &	operator<<( std::ostream &o, Bureaucrat const &src)
{
	o << src.getName() << ", bureaucrat grade "<<src.getGrade()<<"."<<std::endl;
	return o;
}