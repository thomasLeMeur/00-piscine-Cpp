/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 18:37:49 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice")
{
	return;
}

Ice::Ice( Ice const & other ) : AMateria("ice")
{
	*this = other;
	return;
}

Ice::~Ice( void )
{
	return;
}


Ice& Ice::operator=( Ice const & other )
{
	this->setType(other.getType());
	this->setXP(other.getXP());
	return *this;
}

AMateria* Ice::clone( void ) const
{
	return new Ice(*this);
}

void Ice::use( ICharacter& target )
{
	this->AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return;
}
