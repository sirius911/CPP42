/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:41:26 by clorin            #+#    #+#             */
/*   Updated: 2021/09/24 17:41:55 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

# define MAX_MEM	4

class MateriaSource: public IMateriaSource
{

	private:
		AMateria *_memory[MAX_MEM];
	
	public:
		MateriaSource();								//canonique
		MateriaSource(MateriaSource const &);			//canonique
		virtual ~MateriaSource();						//canonique
		MateriaSource &operator=(MateriaSource const &);//canonique
	
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
};

#endif

