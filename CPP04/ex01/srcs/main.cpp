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

static void test(void)
{
	std::cout << "  **  Construct  **" << std::endl;
	Animal* 	medor = new Dog();
	Animal*		papillon = new Cat();
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << "Papillon is a " << papillon->getType() << " -> ";
	papillon->makeSound();

	papillon->add_ideas("Eat a mouse !!");
	papillon->add_ideas("jump on butterflies !");
	papillon->add_ideas("make my toilet");
	papillon->add_ideas("sleeping on parents bed");

	std::cout << "the Papillon's ideas : " << std::endl;
	papillon->show_ideas();
	delete papillon;
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << "medor is a " << medor->getType() << " -> ";
	medor->makeSound();

	medor->add_ideas("take a walk in the trash!");
	medor->add_ideas("pissing on the neighbor's lawn");
	medor->add_ideas("Playing with my favorite bone");
	std::cout << "the Medor's ideas : " << std::endl;
	medor->show_ideas();
	delete medor;
	std::cout << "***************************************************" << std::endl;
	std::cout << "--------------------TEST DEEP COPY-----------------" << std::endl;
	std::cout << "***************************************************" << std::endl;
	Cat	*originalCat = new Cat();
	originalCat->add_ideas("Une idée en l'air");
	std::cout << "  ** copy by constructor copy** " << std::endl;	
	Cat	copyCat(*originalCat);
	std::cout << "------------" << std::endl;
	std::cout << " ideas of originalCat : " << std::endl;
	originalCat->show_ideas();
	std::cout << " ideas of copyCat : (with different memory addresses)" << std::endl;
	copyCat.show_ideas();
	std::cout << "------------" << std::endl;
	std::cout << "  ** copy by operator = ** " << std::endl;
	Cat	*copyCat2 = new Cat();
	*copyCat2 = *originalCat;
	std::cout << " ** delete originalCat **" << std::endl;
	delete originalCat;
	std::cout << " ideas of copyCat : " << std::endl;
	copyCat2->show_ideas();
	delete copyCat2;
}

int		main(int argc, char **argv)
{
	(void) argv;
	if (argc == 1)
	{
		Animal		*spa[10];
		for (int i = 0; i < 10; i++)
		{
			if (i%2 == 0)
			{
				std::cout << "Cat" << std::endl;
				spa[i] = new Cat();
			}
			else
			{
				std::cout << "Dog" << std::endl;
				spa[i] = new Dog();
			}
		}
		for (int i = 0; i < 10; i++)
			delete spa[i];
		return 0;
	}
	test();
	return 0;
}
