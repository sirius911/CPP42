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

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int		main(int argc, char **argv)
{
	//AAnimal	bad;	 not be able to instantiate.
	std::cout << "  **  Construct  **" << std::endl;
	AAnimal* 	medor = new Dog();
	AAnimal*	papillon = new Cat();
	std::cout << "---------------------" << std::endl;
	std::cout << "Papillon is a " << papillon->getType() << " -> ";
	papillon->makeSound();

	papillon->add_ideas("Eat a mouse !!");
	papillon->add_ideas("jump on butterflies !");
	papillon->add_ideas("make my toilet");
	papillon->add_ideas("sleeping on parents bed");

	std::cout << "the Papillon's ideas : " << std::endl;
	papillon->show_ideas();
	delete papillon;

	std::cout << "medor is a " << medor->getType() << " -> ";
	medor->makeSound();

	medor->add_ideas("take a walk in the trash!");
	medor->add_ideas("pissing on the neighbor's lawn");
	medor->add_ideas("Playing with my favorite bone");
	std::cout << "the Medor's ideas : " << std::endl;
	medor->show_ideas();
	delete medor;

	std::cout << "------TEST COPY--------" << std::endl;

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
	
	return 0;
}
