/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 08:57:44 by clorin            #+#    #+#             */
/*   Updated: 2021/09/09 08:57:46 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie	*ZombieHorde( int N, std::string name);

int	main( void )
{
	int		Nb_Zombie = 5;

	std::cout <<  "*** Horde of Zombies ***" << std::endl;
	Zombie	*zombies = ZombieHorde(Nb_Zombie, "Arthur");
	for(int i = 0; i < Nb_Zombie; i++)
		zombies[i].announce();
	delete [] zombies;
	return (0);
}