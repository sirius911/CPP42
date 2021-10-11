/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:03:36 by clorin            #+#    #+#             */
/*   Updated: 2021/09/29 13:04:10 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <stdexcept>

# include "Bureaucrat.hpp"

# define C_GREEN 	"\e[32m"
# define C_RED		"\e[31m"
# define C_YELLOW	"\e[33m"
# define C_CYAN		"\e[34m"
# define C_RESET	"\e[0m"

class Bureaucrat;

class Form
{
	private:
		std::string	const		_name;
		bool					_signed;
		unsigned const			_gradeToSigne;
		unsigned const			_gradeToExec;
	public:
		Form(std::string const &name = "nameForm", unsigned int gradeToSigne = 20, unsigned int gradeToExec = 5);
		Form(Form const &);
		virtual ~Form(void);

		Form			&operator=(Form const &);

	/*-----------------------	Getter	---------------------------*/
		bool						is_signed(void) const;
		std::string	const			&getName(void) const;
		unsigned int				getGradeToSigne(void) const;
		unsigned int				getGradeToExec(void) const;
		virtual std::string 		view(void) const;

	/* --------------------  Functions  ---------------------------*/

		Form				&beSigned(Bureaucrat const &);
		bool				is_executable(Bureaucrat const &) const;

	/* --------------------  Methodes  ----------------------------*/
		virtual void		execute(Bureaucrat const &) const = 0;

	/*-------------------------------------------------------------
							EXCEPTIONS
	---------------------------------------------------------------*/
	class			GradeTooHighException: public std::exception
	{
		virtual const char* what() const throw();
	};
	
	class			GradeTooLowException: public std::exception
	{
		virtual const char* what() const throw();
	};

	class			AlreadySignedException: public std::exception
	{
		virtual const char* what() const throw();
	};

	class			NotSignedToExecute: public std::exception
	{
		virtual const char* what() const throw();
	};

	class			GradeToLowForExec: public std::exception
	{
		virtual const char* what() const throw();
	};

};

/*-------------------------------------------------------------
							OVERLOAD
---------------------------------------------------------------*/

std::ostream &	operator<<(std::ostream &, Form const &);

#endif
