/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:11:41 by clorin            #+#    #+#             */
/*   Updated: 2021/09/28 14:12:19 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include <stdexcept>

# define C_GREEN 	"\e[32m"
# define C_RED		"\e[31m"
# define C_YELLOW	"\e[33m"
# define C_CYAN		"\e[34m"
# define C_RESET	"\e[0m"

static void		ft_error(std::exception &e)
{
	std::cout << C_RED << e.what() << C_RESET << std::endl;
}

int	main()
{

	std::cout << "******************* Test creating *************************" <<std::endl;
	
	try
	{
		std::cout << "\t Try creating 'the Bad' with grade = 151 :" << std::endl;
		Bureaucrat 	*bad = new Bureaucrat("The Bad", 151);
		std::cout << *bad << std::endl;
	}
	catch (std::exception & e)
	{
		ft_error(e);
	}

	try
	{
		std::cout << "\t Try creating 'the Ugly' with grade = 0 :" << std::endl;
		Bureaucrat 	*bad = new Bureaucrat("The Bad", 0);
		std::cout << *bad << std::endl;
	}
	catch (std::exception & e)
	{
		ft_error(e);
	}

	std::cout << "***********************************************************" <<std::endl;
	std::cout << "************************ TEST MODIF ***********************" <<std::endl;
	Bureaucrat 	*good = new Bureaucrat("The Good", 2);
	std::cout << *good <<std::endl;
	try
	{	
		std::cout << "Try increment grade 'the Good' good->incrementGrade(): " <<std::endl;
		good->incrementGrade();
		std::cout << "\t" << *good <<std::endl;
		std::cout << "Try increment grade 'the Good' good->incrementGrade(): " <<std::endl;
		good->incrementGrade();
		std::cout << C_RED << *good << C_RESET << std::endl;
	}
	catch (std::exception & e)
	{
		ft_error(e);
	}
	delete good;
	Bureaucrat *noob = new Bureaucrat("The Noob", 149);
	std::cout << *noob << std::endl;
	try
	{	
		std::cout << "Try decrement grade 'noob' noob->decrementGrade(): " <<std::endl;
		noob->decrementGrade();
		std::cout << "\t" << *noob <<std::endl;
		std::cout << "Try decrement grade 'the noob' noob->decrementGrade(): " <<std::endl;
		noob->decrementGrade();
		std::cout << C_RED << *noob << C_RESET << std::endl;
	}
	catch (std::exception & e)
	{
		ft_error(e);
	}
	delete noob;
	std::cout << "***********************************************************" <<std::endl;

	return 0;
}
