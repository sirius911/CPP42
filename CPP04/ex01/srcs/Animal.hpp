/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:50:07 by clorin            #+#    #+#             */
/*   Updated: 2021/09/23 14:51:01 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string		_type;
		unsigned int	_nbIdeas;

	public:
		Animal( void );						//canonique
		virtual ~Animal();					//canonique
		Animal(Animal const &);				//canonique
		Animal	&operator=(Animal const &);	//canonique

		virtual void	makeSound( void ) const;	//methode
		virtual void	add_ideas(std::string const);
		virtual	void	show_ideas( void ) const;
		std::string		getType( void ) const;
};

#endif
