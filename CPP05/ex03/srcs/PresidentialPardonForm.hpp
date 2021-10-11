/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:00:41 by clorin            #+#    #+#             */
/*   Updated: 2021/09/30 11:01:08 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm: public Form
{
	private:
		std::string const		_target;

	public:
		PresidentialPardonForm(std::string const &target = "target_default");
		PresidentialPardonForm(PresidentialPardonForm const &);
		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm		&operator=(PresidentialPardonForm const &);

		/* ----------------------getter's------------------------------*/
		std::string	const			&getTarget(void)const;
		virtual std::string 		view(void) const;

		/* --------------------  Methodes  ----------------------------*/
		void	execute(Bureaucrat const &) const;
	
};
/*-------------------------------------------------------------
							OVERLOAD
---------------------------------------------------------------*/

std::ostream &	operator<<(std::ostream &, PresidentialPardonForm const &);

#endif