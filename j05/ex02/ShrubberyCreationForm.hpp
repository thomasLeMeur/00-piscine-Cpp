/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/16 14:47:31 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private :
	std::string const	_target;

	ShrubberyCreationForm( void );
	ShrubberyCreationForm( ShrubberyCreationForm const & other );
	ShrubberyCreationForm& operator=( ShrubberyCreationForm const & other );

public:

	ShrubberyCreationForm( std::string const & target );
	virtual ~ShrubberyCreationForm( void );


	bool	execute( Bureaucrat const & executor ) const;

};

#endif // SHRUBBERYCREATIONFORM_HPP
