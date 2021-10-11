/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:00:39 by clorin            #+#    #+#             */
/*   Updated: 2021/10/05 13:00:54 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t           serialize(Data *ptr)
{
        return (reinterpret_cast<uintptr_t>(ptr));
}

Data*                deserialize(uintptr_t raw)
{
        return (reinterpret_cast<Data *>(raw));
}