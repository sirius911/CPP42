/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalaire.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:12:58 by clorin            #+#    #+#             */
/*   Updated: 2021/10/04 15:13:26 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SCALAIRE_HPP
# define SCALAIRE_HPP

// # include <stdexcept>
# include <iostream>
# include <string>

class Scalaire
{
    private:
        Scalaire(void);
        std::string         _value;
        double              _double;

        /*conversion*/
        void        _toChar(void) const;
        void        _toInt(void) const;
        void        _toFloat(void) const;
        void        _toDouble(void) const;

    public:
       
        Scalaire(std::string const &);
        virtual ~Scalaire(void);
        Scalaire(Scalaire const &);

        Scalaire    &operator=(Scalaire const &);

        void        print(void) const;

        /* exception */
        class NotConvertible: public std::exception
        {
            public:
                virtual const char * what() const throw();
        };

        void        parse(void);
};

#endif
