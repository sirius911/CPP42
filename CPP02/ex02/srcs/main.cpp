/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:11:56 by clorin            #+#    #+#             */
/*   Updated: 2021/09/11 19:12:33 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int     main(void) 
{
    Fixed           a;
    Fixed const     b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << "a = " << a << ", b = " << b << " a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "b - a = " << b - a << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    a = a + 2.0f;
    std::cout << "a / b = " << a / b << std::endl;
    std::cout << "a == b = " << ((a == b)? "true":"false") << std::endl;
    std::cout << "a != b = " << ((a != b)? "true":"false") << std::endl;
    std::cout << "a > b = " << ((a > b)? "true":"false") << std::endl;
    std::cout << "a >= b = " << ((a >= b)? "true":"false") << std::endl;
    std::cout << "a < b = " << ((a < b)? "true":"false") << std::endl;
    std::cout << "a <= b = " << ((a <= b)? "true":"false") << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;
    std::cout << Fixed::min(b, a) << std::endl;

    std::cout << "max(" << a << ", " << b << ") = " << max(a,b) << std::endl;
    Fixed c(Fixed(0.0078125f));
    Fixed d;
    d++;
    c++;
    std::cout << "max(" << c << ", " << d << ") = " << max(c, d) << std::endl;
        
   return 0;
}
