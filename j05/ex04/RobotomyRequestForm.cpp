/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/XX/XX XX:XX:XX by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : Form("RobotomyRequestForm", 72, 45), _target("")
{
	srand(time(NULL));
	return;
}

RobotomyRequestForm::RobotomyRequestForm( std::string const & target ) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
	srand(time(NULL));
	return;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & other ) : Form("RobotomyRequestForm", 72, 45), _target(other._target)
{
	srand(time(NULL));
	return;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	return;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( RobotomyRequestForm const & other )
{
	(void)other;
	return *this;
}

bool RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	try
	{
		this->isExecutable(executor);
		std::cout << "Tuuut Puuuiuist Foussssh ........ " << this->_target << (rand() % 100 < 50 ? " has been robotomized successfully" : " it's a failure") << std::endl;
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