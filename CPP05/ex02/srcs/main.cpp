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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <fstream>

void    Presidential_test()
{
    Bureaucrat *                president = new Bureaucrat("Zaphod Beeblebrox", 1);
    Bureaucrat *                trillian = new Bureaucrat("Trillian", 26);
    PresidentialPardonForm *    pardon = new PresidentialPardonForm("Xavier Niel");

    std::cout << C_YELLOW<<"Creating bureaucrats and a PresidentialPardonForm form..."<<C_RESET << std::endl;
    std::cout << *president << std::endl;
    std::cout << *trillian << std::endl;
    std::cout << *pardon << std::endl;

    std::cout << std::endl << C_YELLOW<<"Attempt to execute a form not signed..."<<C_RESET << std::endl;                
    president->executeForm(*pardon);

    std::cout << std::endl << C_YELLOW<<"Trillian try to signe the form..."<<C_RESET << std::endl; 
    trillian->signForm(*pardon);
    std::cout << std::endl << C_YELLOW<<"Trillian must be upgrade ..."<<C_RESET << std::endl; 
    trillian->incrementGrade();
    std::cout << std::endl << C_YELLOW<<"Trillian retry to signe the form..."<<C_RESET << std::endl; 
    trillian->signForm(*pardon);
    std::cout << *pardon << std::endl;

    trillian->executeForm(*pardon);
    president->executeForm(*pardon);

    delete president;
    delete trillian;
    delete pardon;
}

void    Robotomy_test()
{
    Bureaucrat *            colonel = new Bureaucrat("Colonel", 42);
    Bureaucrat *            sergeant = new Bureaucrat("Sergeant", 73);
    RobotomyRequestForm *   order = new RobotomyRequestForm("Steve Jobs");

    std::cout << C_YELLOW<<"Creating bureaucrats and a Robotomy form..."<<C_RESET << std::endl;
    std::cout << *colonel << std::endl;
    std::cout << *sergeant << std::endl;
    std::cout << *order << std::endl;

    std::cout << std::endl << C_YELLOW<<"Attempt to execute a form not signed..."<<C_RESET << std::endl;
    colonel->executeForm(*order);

    sergeant->signForm(*order);

    sergeant->incrementGrade();
    sergeant->signForm(*order);

    std::cout << std::endl << C_YELLOW<<"Attempt to execute a form not authorized for the sergeant..."<<C_RESET << std::endl;
    sergeant->executeForm(*order);

    std::cout << std::endl << C_YELLOW<<"Retry to execute by colonel..."<<C_RESET << std::endl;
    colonel->executeForm(*order);
    colonel->executeForm(*order);
    delete colonel;
    delete sergeant;
    delete order;
}

void    Shrubbery_test()
{
    Bureaucrat *            chief = new Bureaucrat("Chief", 42);
    Bureaucrat *            secretary = new Bureaucrat("Secretary", 142);
    ShrubberyCreationForm * shrubbery = new ShrubberyCreationForm("ChristmasTreesForm");

    std::cout << C_YELLOW<<"Creating bureaucrats and a shrubbery form..."<<C_RESET << std::endl;
    std::cout << *chief << std::endl;
    std::cout << *secretary << std::endl;
    std::cout << *shrubbery << std::endl;

    std::cout << std::endl << C_YELLOW<<"Attempt to execute a form not signed..."<<C_RESET << std::endl;
    chief->executeForm(*shrubbery);

    secretary->signForm(*shrubbery);

    std::cout << std::endl << C_YELLOW<<"Attempt to execute a form not authorized for the secretary..."<<C_RESET << std::endl;
    secretary->executeForm(*shrubbery);

    std::cout << std::endl << C_YELLOW<<"Retry to execute by chief..."<<C_RESET << std::endl;
    chief->executeForm(*shrubbery);

    std::ifstream   file;
    file.open("ChristmasTreesForm_shrubbery");
    if (!file)
    {
        std::cout << "Error reading file ChristmasTreesForm_shrubbery" << std::endl;
    }
    else
    {
        std::cout << "reading the 'ChristmasTreesForm_shrubbery' file >>>" << std::endl;
        std::string line;
        while (getline(file, line))
           std::cout << line << std::endl;
    }
    file.close();

    delete shrubbery;
    delete chief;
    delete secretary;
}

int	main()
{
    std::cout << C_CYAN << "===> TESTING SHRUBBERY  FORM" << C_RESET << std::endl;
    Shrubbery_test();
    std::cout << std::endl;

    std::cout << C_CYAN << "===> TESTING ROBOTOMY  FORM" << C_RESET << std::endl;
    Robotomy_test();
    std::cout << std::endl;

    std::cout << C_CYAN << "===> TESTING PRESIDENTIAL_PARDON  FORM" << C_RESET << std::endl;
    Presidential_test();
    std::cout << std::endl;
    std::cout << C_CYAN << "======================================" << C_RESET << std::endl;
}
