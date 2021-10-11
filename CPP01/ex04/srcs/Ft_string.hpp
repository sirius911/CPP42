/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ft_string.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:57:32 by clorin            #+#    #+#             */
/*   Updated: 2021/09/10 18:58:03 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_HPP
# define FT_STRING_HPP

#include <string>

class   Ft_string
{
    public:
        Ft_string(std::string);
        ~Ft_string( void );

        int             replace(std::string const &, std::string const &);
        std::string     get( void ) const;
        void            add(char const);
        void            add(std::string const);

    private:
        std::string     _string;
};
#endif
