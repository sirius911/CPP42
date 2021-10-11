/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:04:50 by clorin            #+#    #+#             */
/*   Updated: 2021/09/04 18:04:53 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iomanip>
#include <cstring>
#include <locale>

PhoneBook::PhoneBook(void) : _nb_Contact(0), _nb_Max(8)
{
    return;
}

PhoneBook::~PhoneBook(void)
{
    return;
}

int         PhoneBook::getNb_Contact(void) const
{
    return (this->_nb_Contact);
}

void        PhoneBook::add_contact(void)
{
    std::string     first_name, last_name, nickname, phone_number, darkest_secret;
    std::string     yesNo;

    if (this->_nb_Contact >= this->_nb_Max)
    {
        std::cout << "\033[31m"<< "Your PhoneBook is full." << "\033[0m"<< std::endl;
        std::cout << "You will delete the last contact...Do you want to continue ? (Y/N) : ";
        std::getline(std::cin, yesNo);
        if (yesNo.compare("Y") && yesNo.compare("y"))
            return;
        this->_nb_Contact--;
    }
    std::cout << "Please, enter the informations for this new contact : " << std::endl;
    std::cout << "First Name :";
    std::getline(std::cin, first_name);
    std::cout << "last_name : ";
    std::getline(std::cin, last_name);
    std::cout << "nickname : ";
    std::getline(std::cin, nickname);
    std::cout << "phone_number : ";
    std::getline(std::cin, phone_number);
    std::cout << "darkest_secret : ";
    std::getline(std::cin, darkest_secret);
    this->_contact[this->_nb_Contact].input(first_name, last_name, nickname, phone_number, darkest_secret);
    std::cout << "Contact #" << this->_nb_Contact << " registered." << std::endl;
    this->_nb_Contact++;
}

std::string     PhoneBook::_print_col(std::string str)
{
    if (str.size() > 10)
    {
        str = str.insert(9, ".");
        str = str.substr(0, 10);
    }
    return (str);
}

void        PhoneBook::search_contact(void)
{
    int             i;
    std::string     choice;
    int             index;

    i = 0;
    if (this->_nb_Contact > 0)
    {
        std::cout << "|-------------------------------------------|" <<std::endl;
        std::cout << "|   Index  |first name|last name | nickname |" << std::endl;
        std::cout << "|----------|----------|----------|----------|" <<std::endl;
        while (i < this->_nb_Max)
        {
            if (!this->_contact[i].is_empty())
            {
                std::cout << "|" << std::setw(10) << i + 1 << "|" << std::setw(10) << this->_print_col(_contact[i].getFirst_name()) << "|" <<
                std::setw(10) << this->_print_col(_contact[i].getLast_name()) << "|" << std::setw(10) << this->_print_col(_contact[i].getNickname()) << "|" << std::endl;
            }
            i++;
        }
        std::cout << "|-------------------------------------------|" <<std::endl;
        std::cout << "Enter the index of Contact : ";
        std::getline(std::cin, choice);
        index = atoi(choice.c_str());
        if ( index > 0 && index <= this->_nb_Max && !this->_contact[index - 1].is_empty())
            this->_contact[index - 1].print();
        else
            std::cout << "\033[31m" << "Bad index !" << "\033[0m" << std::endl;
    }
    else
    { 
        std::cout << "\033[31m" << "No Contact registered !!" << "\033[0m" << std::endl; 
    }
    
}

std::string     PhoneBook::keyboard_input(std::string prompt) const
{
    std::string input;
    int         i;
    std::locale	loc;
    
    std::cout << prompt;
    std::getline(std::cin, input);
    i = 0;
    while (i < input.length())
    {
        input[i] = std::toupper(input[i], loc);
        i++;
    }
    return (input);
}