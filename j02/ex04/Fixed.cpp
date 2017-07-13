/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/XX/XX XX:XX:XX by student           #+#    #+#             */
/*   Updated: 2017/01/11 18:17:05 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed( void )
{
	this->_value = 0;
	return;
}

Fixed::Fixed( float const n )
{
	int pow = 1;
	for (int i = 0 ; i < Fixed::_point ; i++)
		pow *= 2;
	this->_value = roundf(n * pow);
	return;
}

Fixed::Fixed( int const n )
{
	int pow = 1;
	for (int i = 0 ; i < Fixed::_point ; i++)
		pow *= 2;
	this->_value = roundf(n * pow);
	return;
}

Fixed::Fixed( Fixed const & other )
{
	*this = other;
	return;
}

Fixed::~Fixed( void )
{
	return;
}

Fixed& Fixed::operator=( Fixed const & other )
{
	this->_value = other.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	return this->_value;
}

void Fixed::setRawBits( int const raw )
{
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

bool Fixed::operator>( Fixed const & other ) const
{
	return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<( Fixed const & other ) const
{
	return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>=( Fixed const & other ) const
{
	return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=( Fixed const & other ) const
{
	return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==( Fixed const & other ) const
{
	return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=( Fixed const & other ) const
{
	return (this->toFloat() != other.toFloat());
}

Fixed Fixed::operator+( Fixed const & other ) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-( Fixed const & other ) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*( Fixed const & other ) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/( Fixed const & other ) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++( void )
{
	this->_value++;
	return *this;
}

Fixed& Fixed::operator--( void )
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator++( int )
{
	Fixed tmp(*this);
	this->_value++;
	return tmp;
}

Fixed Fixed::operator--( int )
{
	Fixed tmp(*this);
	this->_value--;
	return tmp;
}

Fixed& Fixed::min( Fixed & var1, Fixed & var2 )
{
	return ( var1 < var2 ) ? var1 : var2;
}

Fixed const & Fixed::min( Fixed const & var1, Fixed const & var2 )
{
	return ( var1 < var2 ) ? var1 : var2;
}

Fixed& Fixed::max( Fixed & var1, Fixed & var2 )
{
	return ( var1 < var2 ) ? var2 : var1;
}

Fixed const & Fixed::max( Fixed const & var1, Fixed const & var2 )
{
	return ( var1 < var2 ) ? var2 : var1;
}

std::ostream & operator<<( std::ostream & stream, Fixed const & var)
{
	return stream << var.toFloat();
}
