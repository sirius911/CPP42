/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:47:17 by clorin            #+#    #+#             */
/*   Updated: 2021/09/27 11:48:43 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# define MAX_INV	4

# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter
{
	private:
		std::string const			_name;
		AMateria*					_inventory[MAX_INV];

	public:
		Character();
		virtual ~Character();
		Character(Character const &);
		Character(std::string const &);
		virtual Character			&operator=(Character const &);

		virtual std::string const	&getName(void) const;
		virtual void				equip(AMateria*);
		virtual void				unequip(int);
		virtual void				use(int, ICharacter &);
};

#endif
