/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 08:58:10 by clorin            #+#    #+#             */
/*   Updated: 2021/09/09 09:01:59 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
	public:

		Zombie( void );
		Zombie( std:: string );
		~Zombie( void );

		void	setName( std::string name);	
		void	announce( void ) const;

	private:
		std:: string	_name;
};
#endif