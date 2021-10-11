/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:33:12 by clorin            #+#    #+#             */
/*   Updated: 2021/09/09 10:33:45 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie	*ZombieHorde( int N, std::string name)
{
	Zombie* zombies	 = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombies[i].setName(name);

	return (zombies);
}