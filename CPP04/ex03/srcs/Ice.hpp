/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:47:02 by clorin            #+#    #+#             */
/*   Updated: 2021/09/24 17:47:25 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CLASSICE_HPP
# define CLASSICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
public:
	Ice( void );					//canonique
	Ice(Ice const &);				//canonique
	virtual ~Ice();					//canonique
	Ice &operator=(Ice const &);	//canonique
	
	virtual	Ice*	clone() const;
	virtual	void	use(ICharacter &);
};

#endif

