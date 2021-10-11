/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:57:09 by clorin            #+#    #+#             */
/*   Updated: 2021/10/08 15:57:59 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>

class Span
{
	private:
		unsigned int 			_n;
		std::vector<int>		_store;	


	public:
		Span(void);
		Span(const int &);
		Span(Span const &);
		virtual ~Span(void);
	
		Span	&operator=(Span const &);

		void	addNumber(int const &);
		
		template <class Iterator>
		void	addNumber(Iterator begin, Iterator end)
		{
			if ((end - begin + this->_store.size() > this->_n))
				throw SpanFullException();
			copy(begin, end, back_inserter(this->_store));
			sort(this->_store.begin(), this->_store.end());
		};

		long	longestSpan(void) const;
		long	shortestSpan(void) const;

		class	SpanFullException: public std::exception
		{
			virtual const char  	*what() const throw();
		};

		class 	SpanInvalidConstructorException: public std::exception
		{
			virtual const char		*what() const throw();			
		};
		class 	SpanNotEnoughValueException: public std::exception
		{
			virtual const char		*what() const throw();
		};

		/* TO DELETE*/
		void	inc(void);
		void	show(void);
};

#endif
