/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/XX/XX XX:XX:XX by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock( void )
{
	this->_intern = 0;
	this->_sign = 0;
	this->_exec = 0;
	return;
}

OfficeBlock::OfficeBlock( Intern* intern, Bureaucrat* sign, Bureaucrat* exec )
{
	this->_intern = intern;
	this->_sign = sign;
	this->_exec = exec;
	return;
}


OfficeBlock::OfficeBlock( OfficeBlock const & other )
{
	*this = other;
	return;
}

OfficeBlock::~OfficeBlock( void )
{
	return;
}

OfficeBlock& OfficeBlock::operator=( OfficeBlock const & other )
{
	this->_intern = other._intern;
	this->_sign = other._sign;
	this->_exec = other._exec;
	return *this;
}

void OfficeBlock::setIntern( Intern & man )
{
	this->_intern = &man;
	return;
}

void OfficeBlock::setSigner( Bureaucrat & man )
{
	this->_sign = &man;
	return;
}

void OfficeBlock::setExecutor( Bureaucrat & man )
{
	this->_exec = &man;
	return;
}

void OfficeBlock::doBureaucracy( std::string const & form, std::string const & target ) const throw(OfficeBlock::MissingEmployeeException)
{
	if (this->_intern == 0 || this->_sign == 0 || this->_exec == 0)
		throw OfficeBlock::MissingEmployeeException();
	else
	{
		try
		{
			Form* myForm = this->_intern->makeForm(form, target);
			this->_sign->signForm(*myForm);
			if (myForm->getSigned())
				this->_exec->executeForm(*myForm);
			delete myForm;
		}
		catch(Intern::UnknownFormException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return;
}
