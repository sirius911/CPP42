/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:26:09 by clorin            #+#    #+#             */
/*   Updated: 2021/10/08 13:26:13 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <vector>

# include "span.hpp"

# define C_GREEN    "\e[32m"
# define C_RED      "\e[31m"
# define C_YELLOW   "\e[33m"
# define C_CYAN     "\e[34m"
# define C_RESET    "\e[0m"

# define MAX_EL 1000000

void		ft_error(std::exception &e)
{
	std::cout << C_RED << "Error by exception : " << C_YELLOW << e.what() << C_RESET << std::endl;
}

void		heavy_values_test()
{
	Span span_larg = Span(2);

    span_larg.addNumber(2147483647);
    span_larg.addNumber(-2147483648);
    std::cout << "span_larg = ";
    span_larg.show();
    std::cout << "span_larg.longestSpan() = "<<span_larg.longestSpan() << std::endl;
    std::cout << "span_larg.shortestSpan()= "<<span_larg.shortestSpan() << std::endl;
}

void		exception_test()
{
	std::cout << "\t-------- add an element beyond the size ------- " << std::endl;
	std::cout << "Span sp = Span(2)" << std::endl;
	Span sp = Span(2);
	sp.show();
	try
	{	
		sp.addNumber(5);
		sp.show();
		sp.addNumber(3);
		sp.show();
		sp.addNumber(42);	// more than 2 elements
		sp.show();
	}
	catch (std::exception &e)
	{
		ft_error(e);
	}	
	sp.show();

	std::cout << "\t-------- Bad constructor ------- " << std::endl;
	try
	{
		std::cout << "bad = Span(-42) ... ";
		Span	bad = Span(-42);
		std::cout << C_RED << " KO, this line must not be here !" << C_RESET << std::endl;
	}
	catch (std::exception &e)
	{
		ft_error(e);
	}	
	std::cout << "\t-------- Not enough value for span ------- " << std::endl;
	Span		sp_empty;
	std::cout << "\twith sp_empty = ";
	sp_empty.show();
	try
	{
		std::cout << "longuestSpan = ";
		std::cout << sp_empty.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		ft_error(e);
	}
	try
	{
		std::cout << "shortestSpan = ";
		std::cout << sp_empty.shortestSpan() << std::endl;
	}	
	catch (std::exception &e)
	{
		ft_error(e);
	}	
	Span		sp_one(1);
	sp_one.addNumber(42);
	std::cout << "\twith sp_one = ";
	sp_one.show();
	try
	{
		std::cout << "longuestSpan = ";
		std::cout << sp_one.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		ft_error(e);
	}
	try
	{
		std::cout << "shortestSpan = ";
		std::cout << sp_one.shortestSpan() << std::endl;
	}	
	catch (std::exception &e)
	{
		ft_error(e);
	}	
}

void		given_test()
{
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int		aleat()
{
	int n = rand() % (MAX_EL);
	int sign = ((rand() % 2 == 0)? 1:-1);
	n *= sign;
	return n;
}
/*******************************************************************************
 * 								M A I N 
 * ******************************************************************************/
int			main()
{
	srand(time(NULL));
	std::cout << "*****************************  G i v e n   T e s t  *****************************" << std::endl;
	given_test();
	std::cout << std::endl<< "***************************  E x c e p t i o n     T e s t s *************************** " << std::endl;
	exception_test();
	std::cout << std::endl<< "*****************************  H e a v y       V a l u e s ***************************** " << std::endl;
	heavy_values_test();
	std::cout << std::endl<< "**************************  "<<MAX_EL<<"        V a l u e s ***************************** " << std::endl;
	
    Span span_heavy = Span(MAX_EL);

    std::vector<int> v(MAX_EL,0);
    generate(v.begin(), v.end(), aleat);
   	
    std::cout << "Before adding " << C_CYAN<<MAX_EL<< C_RESET<<" elements : span_heavy = ";
    span_heavy.show();

    span_heavy.addNumber(v.begin(), v.end());
    if (MAX_EL <= 30)
    {
    	std::cout << "span_heavy = ";
    	span_heavy.show();
    }
    std::cout << "longuest Span = " << span_heavy.longestSpan() << std::endl;
    std::cout << "shortest Span = " << span_heavy.shortestSpan() << std::endl;

	return 0;
}
