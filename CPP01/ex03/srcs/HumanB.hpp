/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:50:53 by clorin            #+#    #+#             */
/*   Updated: 2021/09/10 14:51:28 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string const name);
        ~HumanB();

        void    attack( void ) const;
        void    setWeapon( Weapon &weapon);

    private:
        std::string     _name;
        Weapon          *_weapon;
};

#endif
