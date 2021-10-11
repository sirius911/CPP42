/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 22:09:55 by clorin            #+#    #+#             */
/*   Updated: 2021/09/19 22:13:42 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main( void )
{
	ClapTrap A("Alpha");
	ClapTrap B;

	A.attack("B");
	B.takeDamage(10);

	B.attack("Alpha");
	A.takeDamage(30);
	B.beRepaired(3);

	A.attack("B");
	B.takeDamage(10);

	ClapTrap C("Charlie");

	ClapTrap D;

	D = C;

	return 0;
}
