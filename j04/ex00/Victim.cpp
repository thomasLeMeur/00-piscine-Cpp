/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 13:05:15 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Victim.hpp"

Victim::Victim( void ) : _name("")
{
	std::cout << "It's impossible to see this message" << std::endl;
	return;
}

Victim::Victim( std::string const name ) : _name(name)
{
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
	return;
}

Victim::Victim( Victim const & other )
{
	*this = other;
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
	return;
}

Victim::~Victim( void )
{
	std::cout << "Victim " << this->_name << " just died for no apparent reason" << std::endl;
	return;
}


Victim& Victim::operator=( Victim const & other )
{
	this->_name = other._name;
	return *this;
}

std::string Victim::getName( void ) const
{
	return this->_name;
}

void Victim::getPolymorphed( void ) const
{
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
	return;
}

std::ostream& operator<<( std::ostream& stream, Victim const & obj )
{
	return stream << "I'm " << obj.getName() << " and I like otters !" << std::endl;
}
