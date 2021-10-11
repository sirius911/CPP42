/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:37:56 by clorin            #+#    #+#             */
/*   Updated: 2021/09/10 13:38:34 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"


class HumanA
{
    public:
        HumanA(std::string const name, Weapon &weapon);
        ~HumanA();

        void    attack( void ) const;

    private:
        std::string     _name;
        Weapon          &_weapon;
};
#endif