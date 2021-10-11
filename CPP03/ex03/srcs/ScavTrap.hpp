/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 22:40:39 by clorin            #+#    #+#             */
/*   Updated: 2021/09/19 22:41:07 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(std::string const & name = "Default_ScavTrap" );
	ScavTrap( ScavTrap const & );
	virtual ~ScavTrap( void );

	ScavTrap & operator=(ScavTrap const &);

	void		guardGate( void ) const;
	void		attack(std::string const &);
};

#endif
