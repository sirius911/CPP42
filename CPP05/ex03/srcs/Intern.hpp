/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:56:38 by clorin            #+#    #+#             */
/*   Updated: 2021/10/01 10:57:03 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>

# define NB_FORM	3

class	Form;

class Intern
{
	private:
	
		typedef struct s_Form
		{
				std::string		name_form;
				Form*			(Intern::*function_create_Form)(std::string const &);
		}				t_Form;

		static const t_Form		select_function[NB_FORM];

		Form *	createShrubbery(std::string const &);
		Form *	createRobotomy(std::string const &);
		Form *	createPresidential(std::string const &);

	public:

	Intern();
	Intern(Intern const &);
	virtual ~Intern();

	Intern		&operator=(Intern const &);
	
	Form*		makeForm(std::string const &, std::string const &);
};

#endif