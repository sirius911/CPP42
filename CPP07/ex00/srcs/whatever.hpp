/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:02:22 by clorin            #+#    #+#             */
/*   Updated: 2021/10/07 10:02:58 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template < typename T >
void	swap(T &a, T &b)
{
	T	tmp = a;

	a = b;
	b = tmp;
} 

template < typename T >
T const &	min(T const &a, T const &b)
{
	return ((b <= a) ? b : a);
}


template < typename T >
T const &	max(T const &a, T const &b)
{
	return ((b >= a) ? b : a);
}
#endif
