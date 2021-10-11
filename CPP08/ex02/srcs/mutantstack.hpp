/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:12:41 by clorin            #+#    #+#             */
/*   Updated: 2021/10/10 20:13:08 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

/*template <typename T>
class MutantStack<T>;*/

template <typename T>
class		MutantStack:public std::stack<T>
{
	public:
		/* -------------  Canonique form  -----------------------------*/
		MutantStack<T>():std::stack<T>(){};
		MutantStack<T>(MutantStack const &cpy):std::stack<T>(cpy){};
		virtual ~MutantStack(){};
		MutantStack const &operator=(MutantStack const &cpy)
		{
			if (this != &cpy)
				std::stack<T>::operator=(cpy);
			return *this;
		}
		/* -------------------------------------------------------------*/

		/* iterator*/
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator 				begin(void){return this->c.begin();}
		iterator 				end(void){return this->c.end();}

		const_iterator			begin(void) const {return this->c.begin();}
		const_iterator			end(void) const{return this->c.end();}

		reverse_iterator		rbegin(void){return this->c.rbegin();}
		reverse_iterator		rend(void) {return this->c.rend();}

		const_reverse_iterator	rbegin(void) const {return this->c.rbegin();}
		const_reverse_iterator	rend(void) const {return this->c.rend();}
};
#endif
