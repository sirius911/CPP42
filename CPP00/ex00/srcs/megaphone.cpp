/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 13:34:39 by clorin            #+#    #+#             */
/*   Updated: 2021/09/04 14:38:39 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <locale>

int		main(int argc, char **argv)
{
	int			i;
	size_t		j;
	std::locale	loc;

	if (argc > 1)
	{
		i = 1;
		while(i < argc)
		{
			j = 0;
			while (j < std::strlen(argv[i]))
				std::cout << std::toupper(argv[i][j++], loc);
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
