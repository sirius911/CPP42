/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 09:21:03 by clorin            #+#    #+#             */
/*   Updated: 2021/09/24 09:21:29 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string		_ideas[100];

	public:
		Brain( void );						//canonique
		virtual ~Brain( void );				//canonique
		Brain(Brain const &);				//canonique

		Brain	&operator=(Brain const &);	//canonique*

		void	add(unsigned, std::string);
		void	show(unsigned const) const;
};
#endif
