/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:47:02 by clorin            #+#    #+#             */
/*   Updated: 2021/09/27 12:28:51 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
public:
	Cure( void );					//canonique
	Cure(Cure const &);				//canonique
	virtual ~Cure();				//canonique
	Cure &operator=(Cure const &);	//canonique
	
	virtual	Cure*	clone() const;
	virtual	void	use(ICharacter &);
};

#endif

