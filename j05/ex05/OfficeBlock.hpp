/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/16 14:50:26 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

#include <stdexcept>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

class OfficeBlock
{
public:
	class MissingEmployeeException : public std::exception
	{
	public:
		virtual const char*	what() const throw()
			{
				return ("All the required employees are not here");
			}
	};

private :
	Intern*		_intern;
	Bureaucrat* _sign;
	Bureaucrat* _exec;

	OfficeBlock( OfficeBlock const & other );
	OfficeBlock& operator=( OfficeBlock const & other );

public:

	OfficeBlock( void );
	OfficeBlock( Intern* intern, Bureaucrat* sign, Bureaucrat* exec );
	virtual ~OfficeBlock( void );

	void	setIntern( Intern & man );
	void	setSigner( Bureaucrat & man );
	void	setExecutor( Bureaucrat & man );
	Intern* getIntern( void );

	void	doBureaucracy( std::string const & form, std::string const & target ) const throw(OfficeBlock::MissingEmployeeException);

};

#endif // OFFICEBLOCK_HPP
