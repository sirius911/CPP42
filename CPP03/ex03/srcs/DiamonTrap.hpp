/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamonTrap.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 00:01:15 by clorin            #+#    #+#             */
/*   Updated: 2021/09/20 00:01:44 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONTRAP_HPP
# define DIAMONTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamonTrap: public ScavTrap, public FragTrap
{	
	private:
		std::string		_name;

	public:
		DiamonTrap(std::string const & name = "Default_DiamonTrap" );//canonical form
		DiamonTrap( DiamonTrap const &);							 //canonical form
		virtual ~DiamonTrap( void);									 //canonical form

		DiamonTrap & operator=(DiamonTrap const &);					//canonical form

		void		whoAmi(void) const;
		void		attack(std::string const &);
/*
		void		affiche( void ) const;
		void		set(std::string s, int a, int b, int c);
		*/

};

#endif
