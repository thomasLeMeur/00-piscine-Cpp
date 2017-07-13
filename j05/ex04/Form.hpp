/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/16 14:49:47 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char*	what() const throw()
			{
				return ("The grade is too high");
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char*	what() const throw()
			{
				return ("The grade is too low");
			}
	};
	class FormUnsignedException : public std::exception
	{
		public:
			virtual const char*	what() const throw()
			{
				return ("The form has not been previously signed");
			}
	};

private :
	std::string const	_name;
	bool				_signed;
	unsigned int const	_requiredGradeToSign;
	unsigned int const	_requiredGradeToExecute;

	Form( void );
	Form( Form const & other );
	Form& operator=( Form const & other );

public:

	Form( std::string const & name, unsigned int gradeToSign, unsigned int gradeToExecute ) throw(Form::GradeTooHighException, Form::GradeTooLowException);
	virtual ~Form( void );

	std::string		getName( void ) const;
	bool			getSigned( void ) const;
	unsigned int	getRequiredGradeToSign( void ) const;
	unsigned int	getRequiredGradeToExecute( void ) const;


	void			beSigned( Bureaucrat const & bureaucrat ) throw(Form::GradeTooLowException);
	virtual bool	execute( Bureaucrat const & executor ) const = 0;
	void			isExecutable( Bureaucrat const & executor ) const throw(Form::GradeTooLowException, Form::FormUnsignedException);

};

std::ostream& operator<<( std::ostream & stream, Form const& obj );

#endif // FORM_HPP
