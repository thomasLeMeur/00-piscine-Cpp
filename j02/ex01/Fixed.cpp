/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/XX/XX XX:XX:XX by student           #+#    #+#             */
/*   Updated: 2017/01/11 16:07:32 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;

	this->_value = 0;
	return;
}

Fixed::Fixed( float const n )
{
	std::cout << "Float constructor called" << std::endl;

	int pow = 1;
	for (int i = 0 ; i < Fixed::_point ; i++)
		pow *= 2;
	this->_value = roundf(n * pow);
	return;
}

Fixed::Fixed( int const n )
{
	std::cout << "Int constructor called" << std::endl;

	int pow = 1;
	for (int i = 0 ; i < Fixed::_point ; i++)
		pow *= 2;
	this->_value = roundf(n * pow);
	return;
}

Fixed::Fixed( Fixed const & other )
{
	std::cout << "Copy constructor called" << std::endl;

	*this = other;
	return;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}


Fixed& Fixed::operator=( Fixed const & other )
{
	std::cout << "Assignation operator called" << std::endl;

	this->_value = other.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	return this->_value;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;

	this->_value = raw;
	return;
}

float Fixed::toFloat( void ) const
{
	int pow = 1;
	for (int i = 0 ; i < Fixed::_point ; i++)
		pow *= 2;
	return this->getRawBits() / (float)pow;
}

int Fixed::toInt( void ) const
{
	int pow = 1;
	for (int i = 0 ; i < Fixed::_point ; i++)
		pow *= 2;
	return this->getRawBits() / (float)pow;
}

std::ostream & operator<<( std::ostream & stream, Fixed const & var)
{
	return stream << var.toFloat();
}
