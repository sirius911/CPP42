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
#include <stdexcept>

# define C_GREEN 	"\e[32m"
# define C_RED		"\e[31m"
# define C_YELLOW	"\e[33m"
# define C_CYAN		"\e[34m"
# define C_RESET	"\e[0m"

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
		/* -------------------------------------------------------------------------*/
		
		unsigned int	getGrade(void) const;
		std::string		getName(void) const;

		void			incrementGrade(void);
		void			decrementGrade(void);

		class 			GradeTooHighException: public std::exception
		{
				virtual const char* what() const throw();
		};

		class 			GradeTooLowException: public std::exception
		{
				virtual const char* what() const throw();
		};
};

std::ostream &	operator<<( std::ostream &, Bureaucrat const &);

#endif
