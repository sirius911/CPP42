/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:19:27 by clorin            #+#    #+#             */
/*   Updated: 2021/09/10 15:19:32 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Replace.hpp"

int     main( int argc, char **argv)
{

    if (argc ==4)
    {
        Replace r(argv[1], argv[2], argv[3]);
        return (r.go());
    }
    else
    {
        std::cout << "Usage: " << std::endl;
        std::cout << "replace FILENAME s1 s2" << std::endl;
        return (1);
    }
}
