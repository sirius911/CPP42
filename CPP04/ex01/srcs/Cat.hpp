/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:22:53 by clorin            #+#    #+#             */
/*   Updated: 2021/09/23 15:22:55 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain	*_brain;

	public:
		Cat();
		Cat(Cat const &);
		virtual ~Cat();
		Cat	&operator=(Cat const &);

		virtual void	makeSound( void ) const;
		virtual void	add_ideas(std::string const);
		virtual	void	show_ideas( void ) const;
	
};

#endif