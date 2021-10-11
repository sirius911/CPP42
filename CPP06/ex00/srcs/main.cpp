/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:08:54 by clorin            #+#    #+#             */
/*   Updated: 2021/10/04 15:08:56 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Scalaire.hpp"

int     main(int argc, char **argv)
{
    std::string s;

    if (argc == 2)
    {
        s = argv[1];
        try
        {
            Scalaire scal(s);
            scal.print();
            return 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return 1;
        }
    }
    else
    {
        std::cout << "Usage: ./convert \"literal_to_convert\" [ char | int | flaot | double ]. " << std::endl;
        return 1;
    }
}