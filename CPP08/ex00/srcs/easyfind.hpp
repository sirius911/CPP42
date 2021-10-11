/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:55:44 by clorin            #+#    #+#             */
/*   Updated: 2021/10/08 14:03:07 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept>
# include <algorithm>

class NotFoundException: public std::exception
{
public:
	virtual const char*		what() const throw(){return "Not Found";};
	
};

template <typename T>
typename T::const_iterator		easyfind(T const &container, int const & find)
{
	typename T::const_iterator 	it;
	it = std::find(container.begin(), container.end(), find);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

#endif