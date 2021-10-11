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
#include "Form.hpp"
#include <stdexcept>

static void		ft_error(std::exception &e)
{
	std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
}

int	main()
{
    Form* constitution = new Form("Constitution", 10, 30);
    Form* toHigh;
    Form* toLow;
    
    std::cout << *constitution;
    
    try
    {
        toHigh = new Form("ToHigh", 0, 20);
    }
    catch(std::exception & e)
    {
        ft_error(e);
    }

    try
    {
       toLow = new Form("ToLow", 10, 199);
    }
    catch(std::exception & e)
    {
        ft_error(e);
    }

    Bureaucrat* bob = new Bureaucrat("Bob", 5);
    
    std::cout << *bob;

    bob->signForm(*constitution);

    std::cout << *constitution;

    bob->signForm(*constitution);

    Form* secret = new Form("Secret Constitution", 4, 1);

    std::cout << *secret;
    Bureaucrat* noob = new Bureaucrat("Noob", 12);

    noob->signForm(*secret);
    
    delete constitution;
    delete bob;
    delete secret;
    delete noob;
}
