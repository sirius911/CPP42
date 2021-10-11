/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:49:27 by clorin            #+#    #+#             */
/*   Updated: 2021/10/05 13:36:36 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*       generate(void)
{
    int randomize = rand() % 3;

    if (randomize == 0)
    {
        std::cout << "A\t";
        return (new A());
    }
    else if (randomize == 1)
    {
        std::cout << "B\t";
        return (new B());
    }
    std::cout << "C\t";
    return (new C());
}

void        identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A";
    else if (dynamic_cast<B *>(p))
        std::cout << "B";
    else
        std::cout << "C";
}

void        identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
    }
    catch(const std::exception& e)
    {
    }
}

int     main(void)
{
    Base *obj;

    std::cout << "Class\t*ptr\t&ptr" <<std::endl;
    for (int i = 0; i < 10; i++)
    {
        obj = generate();
        identify(obj);
        std::cout << "\t";
        identify(*obj);
        delete obj;
    }
    return 0;
}
