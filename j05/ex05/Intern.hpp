/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/16 16:03:44 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <stdexcept>
#include "Form.hpp"

class Intern
{
public:
	class UnknownFormException : public std::exception
	{
	public:
		virtual const char* what( void ) const throw()
		{
			return ("The form is unknown");
		}
	};

private:
	Intern( Intern const & other );
	Intern& operator=( Intern const & other );

public:

	Intern( void );
	virtual ~Intern( void );

	Form*	makeForm(std::string const & name, std::string const & target) const throw(Intern::UnknownFormException);

};

#endif // INTERN_HPP
