/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/XX/XX XX:XX:XX by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name(""), _grade(150)
{
	return;
}

Bureaucrat::Bureaucrat( std::string const& name, unsigned int grade ) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException)
	: _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	return;
}

Bureaucrat::Bureaucrat( Bureaucrat const & other ) : _name(other._name), _grade(other._grade)
{
	return;
}

Bureaucrat::~Bureaucrat( void )
{
	return;
}


Bureaucrat& Bureaucrat::operator=( Bureaucrat const & other )
{
	this->_grade = other._grade;
	return *this;
}

std::string Bureaucrat::getName( void ) const
{
	return this->_name;
}

unsigned int Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

void Bureaucrat::upgrade( void ) throw(Bureaucrat::GradeTooHighException)
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
	return;
}

void Bureaucrat::downgrade( void ) throw(Bureaucrat::GradeTooLowException)
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
	return;
}

std::ostream& operator<<( std::ostream& stream, Bureaucrat const & obj )
{
	return stream << obj.getName() << ", bureaucrat grade " << obj.getGrade();
}