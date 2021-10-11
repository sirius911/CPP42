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

void	randomChump(std::string name);
Zombie*	newZombie( std::string name);

int	main( void )
{
	std::cout <<  "*** Zombie on the Heap ***" << std::endl;
	Zombie	*z = newZombie("Arthur");
	z->announce();
	delete z;
	std::cout << "*** Zombie on the stack ***" << std::endl;
	randomChump("Pierre");
	return (0);
}