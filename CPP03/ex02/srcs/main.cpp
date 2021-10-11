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
#include "FragTrap.hpp"
#include <iostream>

int	main( void )
{
	FragTrap A("Alpha");
	ScavTrap B("Beta");

	A.attack("Beta");
	B.takeDamage(30);

	B.attack("Alpha");
	A.takeDamage(20);
	A.beRepaired(15);

	B.guardGate();

	B.beRepaired(10);

	A.highFivesGuys();
	
	return 0;
}
