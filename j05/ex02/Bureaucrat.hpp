/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/16 14:46:37 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
public:
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char*	what() const throw()
			{
				return ("The grade can't be higher than 1");
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char*	what() const throw()
			{
				return ("The grade can't be lower than 150");
			}
	};


protected :
	std::string const	_name;
	unsigned int		_grade;

	Bureaucrat( void );
	Bureaucrat( Bureaucrat const & other );
	Bureaucrat& operator=( Bureaucrat const & other );

public:

	Bureaucrat( std::string const& name, unsigned int grade ) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
	virtual ~Bureaucrat( void );


	std::string		getName( void ) const;
	unsigned int	getGrade( void ) const;
	void			upgrade( void ) throw(Bureaucrat::GradeTooHighException);
	void			downgrade( void ) throw(Bureaucrat::GradeTooLowException);
	void			signForm( Form & form ) const;
	void			executeForm( Form const & form ) const;

};

std::ostream& operator<<( std::ostream & stream, Bureaucrat const& obj );

#endif // BUREAUCRAT_HPP
