/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:57:45 by clorin            #+#    #+#             */
/*   Updated: 2021/10/07 14:58:07 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
private:
	T					*_tab;
	unsigned int		_n;

public:
	/***************   Constructor   ********************/
	Array():_n(0), _tab(new T[0]()){}

	Array(unsigned int const &n):_n(n), _tab(new T[n]()){}

	Array(Array const &cpy):_n(cpy._n), _tab(new T[cpy._n]())
	{
		for(size_t i = 0; i < _n; i++)
			this->_tab[i] = cpy._tab[i];
	}

	/***************   Desstructor   ********************/
	virtual ~Array(){delete [] _tab;}
	
	/***************   Assignation   ********************/
	Array	&operator=(Array const &cpy)
	{
		if (this != &cpy)
		{
			this->_n = cpy._n;
			this->_tab = new T[_n]();
			for (size_t i = 0; i < cpy._n; i++)
				this->_tab[i] = cpy._tab[i];
		}
		return *this;
	}

	T		&operator[](unsigned int const &n)
	{
		if (n >= this->_n)
			throw OutOfLimits();
		return (this->_tab[n]);
	}

	/******************   Getter   ********************/
	unsigned int 		getN(void) const {return this->_n;}


	/***************   Exception   ********************/
	class OutOfLimits: public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Out of limits of the Array");
		}
		
	};
};


#endif
