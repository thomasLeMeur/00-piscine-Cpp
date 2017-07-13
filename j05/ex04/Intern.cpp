/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/16 16:04:10 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern( void )
{
	return;
}

Intern::Intern( Intern const & other )
{
	(void)other;
	return;
}

Intern::~Intern( void )
{
	return;
}

Intern& Intern::operator=( Intern const & other )
{
	(void)other;
	return *this;
}

Form* Intern::makeForm(std::string const & name, std::string const & target) const throw(Intern::UnknownFormException)
{
	if (name == "ShrubberyCreation")
	{
		std::cout << "Intern creates " << name << std::endl;
		return new ShrubberyCreationForm(target);
	}
	else if (name == "RobotomyRequest")
	{
		std::cout << "Intern creates " << name << std::endl;
		return new RobotomyRequestForm(target);
	}
	else if (name == "PresidentialPardon")
	{
		std::cout << "Intern creates " << name << std::endl;
		return new PresidentialPardonForm(target);
	}
	else
	{
		std::cout << "Intern creates nothing" << std::endl;
		throw Intern::UnknownFormException();
		return 0;
	}
}
