/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:58:05 by clorin            #+#    #+#             */
/*   Updated: 2021/10/08 15:58:18 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "span.hpp"

# include <algorithm>

Span::Span():_n(0){}

Span::Span(const int &n)
{
	if (n >=0 )
		this->_n = n;
	else
		throw SpanInvalidConstructorException();
}

Span::~Span(){}

Span::Span(Span const &cpy): _n(cpy._n)
{
	std::cout << "Creator of Span by copy with " << this->_n << " ints in list" << std::endl;
	this->_store = cpy._store;
}

Span	&Span::operator=(Span const &cpy)
{
	if (this != &cpy)
	{
		this->_n = cpy._n;
		this->_store = cpy._store;
	}
	return *this;
}

void	Span::addNumber(int const & number)
{
	if (this->_store.size() < this->_n)
		this->_store.insert(this->_store.end(), number);
	else
		throw SpanFullException();
	std::sort(this->_store.begin(), this->_store.end());
}

long	Span::longestSpan() const
{
	long	longest;
	if (this->_store.size() <= 1)
		throw SpanNotEnoughValueException();
	longest = static_cast<long>(*(this->_store.end() - 1)) - static_cast<long>(*(this->_store.begin()));
	return (longest);
}

long 	Span::shortestSpan() const
{
	long	shortest;
	long	tmp;
	std::vector<int>::const_iterator it = this->_store.begin();

	if (this->_store.size() <= 1)
		throw SpanNotEnoughValueException();
	shortest = (static_cast<long>(this->_store[1]) - static_cast<long>(this->_store[0]));
	/*
	the shortest span can be in the middle of the span. So we have to scan it.
	But it can't be <=0, so we can stop when we find a diff == 0;
	*/
	while (shortest != 0 && it + 1 != this->_store.end())
	{
		tmp = (static_cast<long>(*(it + 1)) - static_cast<long>(*it));
		if (tmp < shortest)
			shortest = tmp;
		it++;
	}
	return (shortest);
}

/*******************************************************************************
								E X C E P T I O N S
*******************************************************************************/

const char		*Span::SpanFullException::what() const throw()
{
	return ("Span is full");
}

const char		*Span::SpanInvalidConstructorException::what() const throw()
{
	return ("Bad arg to constructor of Span");
}

const char		*Span::SpanNotEnoughValueException::what() const throw()
{
	return ("Not enough value");
}

/* a effacer */
void	Span::show(void)
{
	std::vector<int>::iterator		it;

	std::cout << "[";
	for (it = this->_store.begin(); it != this->_store.end(); it++)
	{
		if (it == this->_store.begin())
			std::cout << *it;
		else
			std::cout << ", " << *it;
	}
	std::cout << "]" << std::endl;
}

void	Span::inc(void)
{
	std::vector<int>::iterator		it;

	for (it = this->_store.begin(); it != this->_store.end(); it++)
		(*it)++;
}