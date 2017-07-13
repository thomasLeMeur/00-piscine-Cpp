/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/XX/XX XX:XX:XX by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : _name(""), _signed(false), _requiredGradeToSign(20), _requiredGradeToExecute(100)
{
	return;
}

Form::Form( std::string const & name, unsigned int gradeToSign, unsigned int gradeToExecute ) throw(Form::GradeTooHighException, Form::GradeTooLowException)
	: _name(name), _signed(false), _requiredGradeToSign(gradeToSign), _requiredGradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	return;
}

Form::Form( Form const & other ) : _name(other._name), _signed(other._signed), _requiredGradeToSign(other._requiredGradeToSign), _requiredGradeToExecute(other._requiredGradeToExecute)
{
	return;
}

Form::~Form( void )
{
	return;
}

Form& Form::operator=( Form const & other )
{
	this->_signed = other._signed;
	return *this;
}

std::string Form::getName( void ) const
{
	return this->_name;
}

bool Form::getSigned( void ) const
{
	return this->_signed;
}

unsigned int Form::getRequiredGradeToSign( void ) const
{
	return this->_requiredGradeToSign;
}

unsigned int Form::getRequiredGradeToExecute( void ) const
{
	return this->_requiredGradeToExecute;
}

void Form::beSigned( Bureaucrat const & bureaucrat ) throw(Form::GradeTooLowException)
{
	if (bureaucrat.getGrade() > this->_requiredGradeToSign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
	return;
}

std::ostream& operator<<( std::ostream& stream, Form const & obj )
{
	return stream << obj.getName() << ", grade to sign (" << obj.getRequiredGradeToSign() << "), grade to execute (" << obj.getRequiredGradeToExecute() << ") : " << (obj.getSigned() ? "signed" : "not signed");
}