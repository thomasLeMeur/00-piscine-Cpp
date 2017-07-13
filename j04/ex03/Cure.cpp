/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 18:37:55 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure")
{
	return;
}

Cure::Cure( Cure const & other ) : AMateria("cure")
{
	*this = other;
	return;
}

Cure::~Cure( void )
{
	return;
}


Cure& Cure::operator=( Cure const & other )
{
	this->setType(other.getType());
	this->setXP(other.getXP());
	return *this;
}

AMateria* Cure::clone( void ) const
{
	return new Cure(*this);
}

void Cure::use( ICharacter& target )
{
	this->AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	return;
}
