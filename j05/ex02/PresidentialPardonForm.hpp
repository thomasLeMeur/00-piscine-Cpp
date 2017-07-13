/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/16 14:47:09 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private :
	std::string const	_target;

	PresidentialPardonForm( void );
	PresidentialPardonForm( PresidentialPardonForm const & other );
	PresidentialPardonForm& operator=( PresidentialPardonForm const & other );

public:

	PresidentialPardonForm( std::string const & target );
	virtual ~PresidentialPardonForm( void );


	bool	execute( Bureaucrat const & executor ) const;

};

#endif // PRESIDENTIALPARDONFORM_HPP
