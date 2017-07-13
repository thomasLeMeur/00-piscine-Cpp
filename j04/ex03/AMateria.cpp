/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 18:20:05 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria( void ) : _type(""), _xp(0)
{
	return;
}

AMateria::AMateria( std::string const & type ) : _type(type), _xp(0)
{
	return;
}

AMateria::AMateria( AMateria const & other )
{
	*this = other;
	return;
}

AMateria::~AMateria( void )
{
	return;
}


AMateria& AMateria::operator=( AMateria const & other )
{
	this->_xp = other._xp;
	return *this;
}

std::string const & AMateria::getType( void ) const
{
	return this->_type;
}

unsigned int AMateria::getXP( void ) const
{
	return this->_xp;
}

void AMateria::use( ICharacter& target )
{
	(void)target;
	this->_xp += 10;
	return;
}

void	AMateria::setXP( unsigned int xp )
{
	this->_xp = xp;
	return;
}

void	AMateria::setType( std::string const & type )
{
	this->_type = type;
	return;
}
