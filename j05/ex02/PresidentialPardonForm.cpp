/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/XX/XX XX:XX:XX by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : Form("PresidentialPardonForm", 25, 5), _target("")
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm( std::string const & target ) : Form("PresidentialPardonForm", 25, 3), _target(target)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & other ) : Form("PresidentialPardonForm", 25, 5), _target(other._target)
{
	return;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	return;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( PresidentialPardonForm const & other )
{
	(void)other;
	return *this;
}

bool PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	try
	{
		this->isExecutable(executor);
		std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
		return true;
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Form::FormUnsignedException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return false;
}