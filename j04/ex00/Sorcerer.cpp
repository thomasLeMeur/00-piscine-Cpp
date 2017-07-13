/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 13:16:08 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sorcerer.hpp"

Sorcerer::Sorcerer( void ) : _name(""), _title("")
{
	std::cout << "It's impossible to see this message" << std::endl;
	return;
}

Sorcerer::Sorcerer( std::string const name, std::string const title ) : _name(name), _title(title)
{
	std::cout << this->_name << ", " << this->_title << " is born !" << std::endl;
	return;
}

Sorcerer::Sorcerer( Sorcerer const & other )
{
	*this = other;
	std::cout << this->_name << ", " << this->_title << " is born !" << std::endl;
	return;
}

Sorcerer::~Sorcerer( void )
{
	std::cout << this->_name << ", " << this->_title << " is dead. Consequences will never be the same !" << std::endl;
	return;
}


Sorcerer& Sorcerer::operator=( Sorcerer const & other )
{
	this->_name = other._name;
	this->_title = other._title;
	return *this;
}

std::string Sorcerer::getName( void ) const
{
	return this->_name;
}

std::string Sorcerer::getTitle( void ) const
{
	return this->_title;
}

void Sorcerer::polymorph( Victim const & victim) const
{
	victim.getPolymorphed();
	return;
}

std::ostream& operator<<( std::ostream& stream, Sorcerer const & obj )
{
	return stream << "I am " << obj.getName() << ", " << obj.getTitle() << ", and I like ponies !" << std::endl;
}
