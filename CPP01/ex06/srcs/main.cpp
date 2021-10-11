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

int     search_level(std::string const &level, std::string _level[4])
{
    for (int i = 0; i < 4; i++)
        if (!level.compare(_level[i]))
            return (i);
    return (-1);
}

int     main(int argc, char **argv)
{
    Karen   a;
    int     level;

    if (argc == 2)
    {
        std::string _level[4] = {
            "DEBUG",
            "INFO",
            "WARNING",
            "ERROR"
        };
        if ((level = search_level(argv[1], _level)) >= 0)
        {
            while(level < 4)
            {
                std::cout << "[ " << _level[level] << " ]" << std::endl;
                a.complain(_level[level++]);
            }
        }
        else
        {
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        }
    }
    return 0;
}