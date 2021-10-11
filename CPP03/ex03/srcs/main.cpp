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
#include "DiamonTrap.hpp"
#include <iostream>

int	main( void )
{

	DiamonTrap D("Diamon");

	D.attack("Bad_boy");
	D.takeDamage(10);
	
	D.guardGate();
	D.highFivesGuys();

	D.whoAmi();
/*
	std::cout << "***********************************" << std::endl;
	std::cout << "Copie de D" << std::endl;
	DiamonTrap Copie;
	Copie = D;
	Copie.affiche();
	Copie.whoAmi();
	std::cout << " D.set()" << std::endl;
	D.set("essais", 200, 300, 42);
	D.affiche();
	Copie.affiche();*/
	
	return 0;
}
