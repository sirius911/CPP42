/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:59:19 by clorin            #+#    #+#             */
/*   Updated: 2021/09/30 10:59:51 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm: public Form
{
	private:
		std::string const		_target;

	public:
		RobotomyRequestForm(std::string const &target = "target_default");
		RobotomyRequestForm(RobotomyRequestForm const &);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm		&operator=(RobotomyRequestForm const &);

		/* ----------------------getter's------------------------------*/
		std::string	const			&getTarget(void)const;
		virtual std::string 		view(void) const;

		/* --------------------  Methodes  ----------------------------*/
		void	execute(Bureaucrat const &) const;
};

/*-------------------------------------------------------------
							OVERLOAD
---------------------------------------------------------------*/

std::ostream &	operator<<(std::ostream &, RobotomyRequestForm const &);

#endif
