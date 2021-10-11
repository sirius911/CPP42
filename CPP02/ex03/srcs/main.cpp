/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:11:56 by clorin            #+#    #+#             */
/*   Updated: 2021/09/11 19:12:33 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool    bsp( Point const a, Point const b, Point const c, Point const point);

int     main(void) 
{
    Point   A;
    Point   B(Fixed(5), Fixed(4));
    Point   C(Fixed(5), Fixed(0));
    Point   M(Fixed(3.f), Fixed(2));
    
    if (bsp(A, B, C, M))
        std::cout << "M" << M << " inside the triangle " << A << " " << B << " " << C << std::endl; 
    else
        std::cout << "M" << M << " outside the triangle " << A << " " << B << " " << C << std::endl; 
    return 0;
}
