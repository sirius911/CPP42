/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:22:18 by clorin            #+#    #+#             */
/*   Updated: 2021/09/23 15:22:31 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain	*_brain;

	public:
		Dog();
		Dog(Dog const &);
		virtual ~Dog();
		Dog	&operator=(Dog const &);

		virtual void	makeSound( void ) const;
		virtual void	add_ideas(std::string const);
		virtual	void	show_ideas( void ) const;
};

#endif