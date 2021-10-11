/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:38:12 by clorin            #+#    #+#             */
/*   Updated: 2021/09/09 11:39:56 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WEAPON_HPP
# define WEAPON_HPP

class	Weapon
{
	public:
		Weapon( void );
		Weapon( std::string );
		~Weapon( void );

		std::string	const &	getType( void ) const;
		void				setType( std::string );

	private:
		std::string		_type;

};

#endif
