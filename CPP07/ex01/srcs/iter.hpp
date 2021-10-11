/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:37:55 by clorin            #+#    #+#             */
/*   Updated: 2021/10/07 12:38:16 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ITER_HPP
# define ITER_HPP

template< typename T>
void		iter(T *array, size_t const size, void (*f)(T &))
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

#endif
