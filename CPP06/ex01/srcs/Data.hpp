/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:50:46 by clorin            #+#    #+#             */
/*   Updated: 2021/10/05 12:56:50 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DATA_HPP
# define DATA_HPP

# include <stdint.h>
# include <string>

struct Data
{
    std::string     s;
    int             i;
};

uintptr_t           serialize(Data *ptr);
Data                *deserialize(uintptr_t raw);

#endif