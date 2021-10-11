/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:31:56 by clorin            #+#    #+#             */
/*   Updated: 2021/09/16 10:31:58 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Point.hpp"

static bool     sign(Fixed const fixed)
{
    if (fixed >= 0)
        return true;
    else
        return false;
}

bool    bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed r = ((a.getX() - point.getX())*(b.getY() - point.getY())) - ((a.getY() - point.getY())*(b.getX() - point.getX()));
    Fixed s = ((b.getX() - point.getX())*(c.getY() - point.getY())) - ((b.getY() - point.getY())*(c.getX() - point.getX()));
    Fixed t = ((c.getX() - point.getX())*(a.getY() - point.getY())) - ((c.getY() - point.getY())*(a.getX() - point.getX()));

    return (sign(r) == sign(s) && sign(s) == sign(t));
}
