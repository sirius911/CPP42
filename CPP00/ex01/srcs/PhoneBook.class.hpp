/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 17:54:09 by clorin            #+#    #+#             */
/*   Updated: 2021/09/04 17:54:51 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"

class   PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);
    
        int         getNb_Contact(void) const;
        void        add_contact(void);
        void        search_contact(void);
        std::string keyboard_input(std::string) const;

    private:

        int         _nb_Contact;
        int         _nb_Max;

        Contact     _contact[8];
        std::string _print_col(std::string str);
};

#endif
