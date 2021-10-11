/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:50:07 by clorin            #+#    #+#             */
/*   Updated: 2021/09/23 14:51:01 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	protected:
		std::string		_type;
		unsigned int	_nbIdeas;

	public:
		AAnimal( void );						//canonique
		virtual ~AAnimal();						//canonique
		AAnimal(AAnimal const &);				//canonique
		AAnimal	&operator=(AAnimal const &);	//canonique

		virtual void	makeSound( void ) const = 0;	//methode 
		virtual void	add_ideas(std::string const) = 0;
		virtual	void	show_ideas( void ) const = 0;
		std::string		getType( void ) const;
};

#endif
