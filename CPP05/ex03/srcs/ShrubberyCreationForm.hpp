/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:57:44 by clorin            #+#    #+#             */
/*   Updated: 2021/09/30 10:58:21 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm:public Form
{
	private:
		std::string const		_target;

	public:
		ShrubberyCreationForm(std::string const &target = "target_default");
		ShrubberyCreationForm(ShrubberyCreationForm const &);
		virtual	~ShrubberyCreationForm(void);

		ShrubberyCreationForm		&operator=(ShrubberyCreationForm const &);

		/* ----------------------getter's------------------------------*/
		std::string	const			&getTarget(void) const;
		virtual std::string 		view(void) const;

		/* --------------------  Methodes  ----------------------------*/
		void	execute(Bureaucrat const &) const;
};

/*-------------------------------------------------------------
							OVERLOAD
---------------------------------------------------------------*/

std::ostream &	operator<<(std::ostream &, ShrubberyCreationForm const &);

#endif
