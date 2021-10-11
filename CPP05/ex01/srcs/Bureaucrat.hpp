/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:10:35 by clorin            #+#    #+#             */
/*   Updated: 2021/09/28 14:11:06 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:

		std::string	const	_name;
		unsigned int		_grade;

	public:
		/* Canonique ---------------------------------------------------------------*/
		Bureaucrat(std::string const &name = "Default_Name", unsigned int grade = 75);
		Bureaucrat(Bureaucrat const &);
		virtual ~Bureaucrat(void);

		Bureaucrat const &operator=(Bureaucrat const &);
		
		/*--------------------------- Getter's -------------------------------------*/
		unsigned int	getGrade(void) const;
		std::string		getName(void) const;

		/* ---------------------------  Functions  ---------------------------------*/
		void			incrementGrade(void);
		void			decrementGrade(void);
		void			signForm(Form &);

		/*-------------------------------------------------------------
							EXCEPTIONS
		---------------------------------------------------------------*/
		class 			GradeTooHighException: public std::exception
		{
				virtual const char* what() const throw();
		};

		class 			GradeTooLowException: public std::exception
		{
				virtual const char* what() const throw();
		};
};

/*-------------------------------------------------------------
							OVERLOAD
---------------------------------------------------------------*/
std::ostream &	operator<<( std::ostream &, Bureaucrat const &);

#endif
