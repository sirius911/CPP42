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
#include "ScavTrap.hpp"
#include <iostream>

int	main( void )
{
	ClapTrap A("Alpha");
	ScavTrap B("Beta");

	ScavTrap C(B);
	ScavTrap D;

	D = B;

	A.attack("Beta");
	B.takeDamage(0);

	B.attack("Alpha");
	A.takeDamage(20);
	B.beRepaired(30);

	B.guardGate();
	
	return 0;
}
