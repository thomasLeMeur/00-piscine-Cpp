/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/16 14:47:20 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private :
	std::string const	_target;

	RobotomyRequestForm( void );
	RobotomyRequestForm( RobotomyRequestForm const & other );
	RobotomyRequestForm& operator=( RobotomyRequestForm const & other );


public:
	RobotomyRequestForm( std::string const & target );
	virtual ~RobotomyRequestForm( void );


	bool	execute( Bureaucrat const & executor ) const;

};

#endif // ROBOTOMYREQUESTFORM_HPP
