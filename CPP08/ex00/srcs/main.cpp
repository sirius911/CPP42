/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:26:09 by clorin            #+#    #+#             */
/*   Updated: 2021/10/08 13:26:13 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <vector>
# include <list>
# include <map>
# include "easyfind.hpp"

# define MAX_EL	10
# define C_GREEN    "\e[32m"
# define C_RED      "\e[31m"
# define C_YELLOW   "\e[33m"
# define C_CYAN     "\e[34m"
# define C_RESET    "\e[0m"


/******************************************************************************
 * 		Template function who randomize the container
 * ****************************************************************************/
template <typename T>
void							 aleat(T &container)
{
	typename T::iterator			it;
	int good = rand() % MAX_EL;
	int i = 0;

	std::cout << "(";
	for(it = container.begin(); it != container.end(); it++){
		if (i++ == good)
			*it = 42;
		else
			*it = rand() % MAX_EL;
		if (it == container.begin())
			std::cout << *it;
		else
			std::cout <<", " << *it;
	}
	std::cout << ")" << std::endl;
}

/*******************************************************************************
 * 					Tests for container list
 * ******************************************************************************/
void		list_test(void)
{
	std::list<int>			lists(MAX_EL);

	std::cout << "List = ";
	aleat(lists);

	try
	{
		std::cout << "Searching '42' in lists ... ";
		bool find = (*easyfind(lists, 42) == 42) ;
		if (find) std::cout << C_GREEN << " Found" << C_RESET << std::endl;
		std::cout << "Searching '-42' in lists ...";
		find = (*easyfind(lists, -42) == -42);
		if (find) std::cout << C_GREEN << " Found" << C_RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << C_RED << e.what() << C_RESET << std::endl;
	}
}

/*******************************************************************************
 * 					Tests for container Vector
 * ******************************************************************************/

void		vector_test(void)
{
	std::vector<int>		vectors(MAX_EL);

	std::cout << "Vector = ";
	aleat(vectors);

	try
	{
		std::cout << "Searching '42' in vectors ... ";
		bool find = (*easyfind(vectors, 42) == 42) ;
		if (find) std::cout << C_GREEN << " Found" << C_RESET << std::endl;
		std::cout << "Searching '-42' in vectors ...";
		find = (*easyfind(vectors, -42) == -42);
		if (find) std::cout << C_GREEN << " Found" << C_RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << C_RED << e.what() << C_RESET << std::endl;
	}
}


/*******************************************************************************
 * 								M A I N 
 * ******************************************************************************/
int			main()
{
	srand(time(NULL));
	std::cout <<  "************** T E S T S    With     V e c t o r *******************" << std::endl;
	vector_test();
	std::cout << std::endl <<  "************** T E S T S    With     L i s t *******************" << std::endl;
	list_test();
	return 0;
}
