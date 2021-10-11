/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:04:15 by clorin            #+#    #+#             */
/*   Updated: 2021/09/29 13:04:29 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(std::string const &name, unsigned int gradeToSigne, unsigned int gradeToExec):
_name(name), _gradeToSigne(gradeToSigne), _gradeToExec(gradeToExec), _signed(false)
{
	if (gradeToSigne > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
	else if (gradeToSigne < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
}

Form::Form(Form const &copy):
_name(copy._name), _gradeToSigne(copy._gradeToSigne), _gradeToExec(copy._gradeToExec), _signed(false)
{
	if (this->_gradeToSigne > 150 || this->_gradeToExec > 150)
		throw Form::GradeTooLowException();
	else if (this->_gradeToSigne < 1 || this->_gradeToExec < 1)
		throw Form::GradeTooHighException();
}

Form::~Form()
{}

Form			&Form::operator=(Form const &copy)
{
	if (this != &copy)
	{
		if (copy._gradeToSigne > 150 || copy._gradeToExec > 150)
			throw Form::GradeTooLowException();
		else if (copy._gradeToSigne < 1 || copy._gradeToExec < 1)
			throw Form::GradeTooHighException();
		else
			*this = copy;
	}
	return *this;	
}

	/*-----------------------	Getter	---------------------------*/
bool			Form::is_signed() const
{
	return this->_signed;
}
	
std::string	const	&Form::getName() const
{
	return this->_name;
}

unsigned int		Form::getGradeToSigne() const
{
	return this->_gradeToSigne;
}

unsigned int		Form::getGradeToExec() const
{
	return this->_gradeToExec;
}

/* --------------------  Functions  ---------------------------*/

std::string 		Form::view() const
{
	std::string		str("Form <");

	str.append(C_YELLOW + this->_name + C_RESET);// = "Form <" + C_YELLOW + this->_name + C_RESET + "> " + C_RESET;
	str.append("> ");
	//str += "\t(Level to signe :" + this->_gradeToSigne + ") (level to Exec : " + this->_gradeToExec + ") ";
	if (this->_signed)
	{	str.append(C_GREEN);
		str.append(" Signed");
		//str += C_GREEN + " Signed";
	}
	else
	{
		str.append(C_RED);
		str.append(" not Signed");
		//str += C_RED + " not Signed";
	}
	str.append(C_RESET);
	str.append("\n");
	//str += C_RESET + std::endl;
	
	return str;
}

Form			&Form::beSigned(Bureaucrat const &b)
{
	if (this->_signed)
		throw Form::AlreadySignedException();
	else if (b.getGrade() <= this->_gradeToSigne)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
	return *this;
}

bool			Form::is_executable(Bureaucrat const &b) const
{
	if (this->_signed == false)
		throw Form::NotSignedToExecute();
	else if (b.getGrade() > this->_gradeToExec)
		throw Form::GradeToLowForExec();
	return true;
}

/*-------------------------------------------------------------
							EXCEPTIONS
---------------------------------------------------------------*/

const char*		Form::GradeTooHighException::what() const throw()
{
	return ("Exception: The grade must be >= 1");	
}

const char*		Form::GradeTooLowException:: what() const throw()
{
	return ("Exception: The grade must be <= 150");
}

const char*		Form::AlreadySignedException:: what() const throw()
{
	return ("already signed");
}

const char*		Form::NotSignedToExecute:: what() const throw()
{
	return ("not signed");
}

const char*		Form::GradeToLowForExec:: what() const throw()
{
	return ("Grade to low to execute Form");
}
/*-------------------------------------------------------------
							OVERLOAD
---------------------------------------------------------------*/

std::ostream &	operator<<( std::ostream &o, Form const &src)
{
	o << "Form <" <<C_YELLOW<< src.getName() << C_RESET<< "> "<<C_RESET;
	o <<"\t(Level to signe :" << src.getGradeToSigne()<<") (level to Exec : "<<src.getGradeToExec()<<") ";
	if (src.is_signed())
		o << C_GREEN << " Signed";
	else
		o << C_RED << " not signed";
	o << C_RESET << std::endl;
	return o;
}