/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 13:17:01 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Peon.hpp"

Peon::Peon( void ) : Victim("")
{
	std::cout << "It's impossible to see this message" << std::endl;
	return;
}

Peon::Peon( std::string const name ) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::Peon( Peon const & other )
{
	*this = other;
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::~Peon( void )
{
	std::cout << "Bleuark..." << std::endl;
	return;
}


Peon& Peon::operator=( Peon const & other )
{
	this->_name = other._name;
	return *this;
}

void Peon::getPolymorphed( void ) const
{
	std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
	return;
}
