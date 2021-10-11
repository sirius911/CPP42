/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:58:19 by clorin            #+#    #+#             */
/*   Updated: 2021/09/19 19:58:58 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

# define C_GREEN 	"\e[32m"
# define C_RED		"\e[31m"
# define C_YELLOW	"\e[33m"
# define C_CYAN		"\e[34m"
# define C_RESET	"\e[0m"

class ClapTrap
{

	private:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;

	public:						
		ClapTrap(std::string const & name = "Default_ClapTrap" );	//canonical form				
		virtual ~ClapTrap( void );							//canonical form
		ClapTrap( ClapTrap const & );						//canonical form

		ClapTrap & operator=(ClapTrap const &);				//canonical form

		void			attack(std::string const &);
		void			takeDamage(unsigned int);
		void			beRepaired(unsigned int);

};

#endif
