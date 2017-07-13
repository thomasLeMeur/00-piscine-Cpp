/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:58:52 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 12:05:01 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( void )
{
	return;
}

Zombie::Zombie( std::string const type, std::string const name ) : _type(type), _name(name)
{
	this->announce();
	return;
}

Zombie::~Zombie( void )
{
	std::cout << "'" << this->_name << "' died" << std::endl;
	return;
}

void Zombie::setTypeName( std::string type, std::string name )
{
	this->_type = type;
	this->_name = name;
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss..." << std::endl;
	return;
}

void Zombie::announce( void ) const
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss..." << std::endl;
}
