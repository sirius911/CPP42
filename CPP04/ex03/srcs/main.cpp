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

# include "MateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# include "Character.hpp"
#include <iostream>

int		main(int argc, char ** argv)
{
	IMateriaSource *src = new MateriaSource();

	src->learnMateria(new Ice()); 
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp1, *tmp2;
	tmp1 = src->createMateria("ice");
	me->equip(tmp1);
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	if (argc > 1)
	{
		std::cout << "********************************************************************" << std::endl;
		std::cout << "                  		T E S T       C O P Y" <<std::endl;
		std::cout << "********************************************************************" << std::endl;
		std::cout << C_RED << "    Copy of MateriaSource "<<C_RESET<<std::endl;
		MateriaSource *copy_src = new MateriaSource(*dynamic_cast<MateriaSource*>(src));
		std::cout << C_RED << "     Delete of "<<C_YELLOW<<"src"<< C_RESET <<std::endl;
		delete src;
		std::cout << C_RED << "    Copy of Character "<<C_YELLOW<<"me"<<C_RESET<<std::endl;
		Character *copyMe = new Character(*dynamic_cast<Character*>(me));
		std::cout << C_RED << "     Delete of "<<C_YELLOW<<me->getName()<< C_RESET <<std::endl;
		delete me;
		tmp1 = copy_src->createMateria("bad");
		tmp2 = copy_src->createMateria("ice");
		tmp1 = copy_src->createMateria("cure");
		copyMe->equip(tmp1);
		copyMe->equip(tmp2);
		copyMe->use(0,*bob);
		copyMe->use(1,*bob);
		copyMe->use(2,*bob);
		copyMe->use(3,*bob);

		delete copy_src;
		delete copyMe;
	}
	else
	{
			delete src;
			delete me;
	}
	delete bob;

	
	return 0;
}
