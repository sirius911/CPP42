/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:58:23 by clorin            #+#    #+#             */
/*   Updated: 2021/09/04 17:14:00 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iomanip>

#include "PhoneBook.class.hpp"

std::string	menu(const PhoneBook phone)
{
 	std::cout << " _____   _   _   _____   __   _   _____   _____   _____   _____   _   _   " << std::endl;
 	std::cout << "|  _  \\ | | | | /  _  \\ |  \\ | | | ____| |  _  \\ /  _  \\ /  _  \\ | | / /  " << std::endl;
 	std::cout << "| |_| | | |_| | | | | | |   \\| | | |__   | |_| | | | | | | | | | | |/ /   " << std::endl;
 	std::cout << "|  ___/ |  _  | | | | | | |\\   | |  __|  |  _  { | | | | | | | | | |\\ \\   " << std::endl;
 	std::cout << "| |     | | | | | |_| | | | \\  | | |___  | |_| | | |_| | | |_| | | | \\ \\  " << std::endl;
 	std::cout << "|_|     |_| |_| \\_____/ |_|  \\_| |_____| |_____/ \\_____/ \\_____/ |_|  \\_\\ " << std::endl;
 	std::cout << phone.getNb_Contact() << " contact(s) registered." << std::endl;
	return (phone.keyboard_input("Type your command (ADD, SEARCH, EXIT): "));
}

int	main(void)
{
	std::string		entry;
	PhoneBook	phoneBook;
	while (42)
	{
		entry = menu(phoneBook);
		if (entry.compare("EXIT") == 0)
		{
			std::cout << "\033[34m" << "Bye !" << "\033[0m" << std::endl;
			return (0);
		}
		else if (entry.compare("ADD") == 0)
			phoneBook.add_contact();
		else if (entry.compare("SEARCH") == 0)
			phoneBook.search_contact();
		else
			std::cout << "\033[31m" << "[" << entry << "] Bad command !" << "\033[0m" << std::endl;
	}
}
