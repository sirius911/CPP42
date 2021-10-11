/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:50:07 by clorin            #+#    #+#             */
/*   Updated: 2021/09/23 14:51:01 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string		_type;

	public:
		WrongAnimal( void );							//canonique
		virtual ~WrongAnimal();							//canonique
		WrongAnimal(WrongAnimal const &);				//canonique
		WrongAnimal	&operator=(WrongAnimal const &);	//canonique

		void			makeSound( void ) const;	
		std::string		getType( void ) const;
};

#endif
