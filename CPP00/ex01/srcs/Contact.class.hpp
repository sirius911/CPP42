/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:05:26 by clorin            #+#    #+#             */
/*   Updated: 2021/09/04 17:16:55 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>

class	Contact
{
	public:
		Contact(void);
		~Contact(void);

		std::string	getFirst_name(void) const;
		std::string	getLast_name(void) const;
		std::string	getNickname(void) const;
		std::string	getPhone_number(void) const;
		std::string	getDarkest_secret(void) const;
		bool		is_empty(void) const;
		bool		input(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5);
		void		print(void);

	private:

		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
		bool		_is_empty;
};

#endif
