/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:33:33 by clorin            #+#    #+#             */
/*   Updated: 2021/09/24 17:34:15 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

# define C_GREEN 	"\e[32m"
# define C_RED		"\e[31m"
# define C_YELLOW	"\e[33m"
# define C_CYAN		"\e[34m"
# define C_RESET	"\e[0m"

class ICharacter;

class AMateria
{
	protected:
		std::string		_type;

	public:
		AMateria( void );				//canonique
		AMateria(std::string const & type);
		AMateria(AMateria const &);		//canonique
		virtual ~AMateria(void);		//canonique
	
		AMateria &operator=(AMateria const &);	//canonique

		std::string	const	&getType() const;	//Accessor

		virtual	AMateria*	clone() const = 0;
		virtual	void		use(ICharacter & target);
};

#endif

