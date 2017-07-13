/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:58:52 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 13:29:48 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB( std::string name) : _name(name)
{
	return;
}

HumanB::~HumanB( void )
{
	return;
}

void HumanB::attack( void ) const
{
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
	return;
}

void HumanB::setWeapon( Weapon& weapon )
{
	this->_weapon = &weapon;
	return;
}
