/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:07:16 by clorin            #+#    #+#             */
/*   Updated: 2021/09/09 11:07:47 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int		main( void )
{
	std::string		str;
	str = "HI THIS IS BRAIN";

	std::string *stringPTR;
	stringPTR = &str;

	std::string & stringREF = str;

	std::cout << "The string [" << str << "] is in this memory adress: " << &str << std::endl;
	std::cout << "\t pointed by 'stringPTR' = " << stringPTR << ((&str == stringPTR)? " \033[34mOK\033[0m":" \033[31mKO\033[0m") << std::endl;
	std::cout << "\t or by '&stringREF' = " << &stringREF << ((&str == &stringREF)? " \033[34mOK\033[0m":" \033[31mKO\033[0m" ) << std::endl;

	return (0);
}