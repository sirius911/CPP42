/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:49:27 by clorin            #+#    #+#             */
/*   Updated: 2021/10/05 12:49:40 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"

int     main(void)
{
    struct Data before;

    before.s = "abcdefghijklmnopqrstuvw!@#$$%^&^&*(&*()*()_)(_+xyz";
    before.i = before.s.size();

    std::cout << "Data.s = " << before.s << std::endl;
    std::cout << "Data.i = " << before.i <<std::endl;
    std::cout << "\tat memory address = &" << &before << std::endl;
    
    uintptr_t   serial;

    serial = serialize(&before);
    std::cout << "serialize(before) = " << serial << std::endl;
    
    struct Data *after;
    after = deserialize(serial);
    std::cout << "after.s = " << after->s << std::endl;
    std::cout << "after.i = " << after->i <<std::endl;
    std::cout << "\tat memory address = " << after << std::endl;
    return 0;
}
