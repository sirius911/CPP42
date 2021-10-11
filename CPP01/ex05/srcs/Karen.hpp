/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 10:54:14 by clorin            #+#    #+#             */
/*   Updated: 2021/09/11 10:54:39 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>

class Karen
{
private:
    void    debug( void );
    void    info( void );
    void    warning( void );
    void    error( void );

public:
    Karen( void );
    ~Karen( void );

    void    complain( std::string level );
};
#endif
