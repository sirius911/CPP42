/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 10:53:59 by clorin            #+#    #+#             */
/*   Updated: 2021/09/11 10:54:01 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int     main(int argc, char **argv)
{
    Karen   a;

    if (argc == 2)
    {
        a.complain(argv[1]);
    }
    else
    {
        std::cout << "***** DEBUG *****" << std::endl;
        a.complain("DEBUG");
        std::cout << "***** INFO *****" << std::endl;
        a.complain("INFO");
        std::cout << "***** WARNING *****" << std::endl;
        a.complain("WARNING");
        std::cout << "***** ERROR *****" << std::endl;
        a.complain("ERROR");
    }
    return 0;
}