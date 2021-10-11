/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:44:47 by clorin            #+#    #+#             */
/*   Updated: 2021/09/19 23:45:22 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:

		FragTrap(std::string const & name = "Default_FragTrap" );
		FragTrap( FragTrap const & );
		virtual ~FragTrap( void );

		FragTrap & operator=(FragTrap const &);

	void		highFivesGuys( void ) const;
	
};
#endif
