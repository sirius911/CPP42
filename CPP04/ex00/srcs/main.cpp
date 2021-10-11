/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:49:32 by clorin            #+#    #+#             */
/*   Updated: 2021/09/23 14:49:34 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int		main()
{
	const Animal* 	meta = new Animal();
	const Animal* 	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	std::cout << "------------" << std::endl;
	const WrongAnimal*	metaWrong = new WrongAnimal();
	const WrongAnimal*	badCat = new WrongCat();

	std::cout << "badCat->getType() = " << badCat->getType() << " " << std::endl;
	badCat->makeSound(); 	// should not work like cat !!
	metaWrong->makeSound();

	delete metaWrong;
	delete badCat;
	return 0;
}
