/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 14:23:15 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PowerFist.hpp"

PowerFist::PowerFist( void ) : AWeapon("Power Fist", 8, 50)
{
	return;
}

PowerFist::PowerFist( PowerFist const & other ) : AWeapon(other._name, other._apcost, other._damage)
{
	return;
}

PowerFist::~PowerFist( void )
{
	return;
}


PowerFist& PowerFist::operator=( PowerFist const & other )
{
	this->_name = other._name;
	this->_damage = other._damage;
	this->_apcost = other._apcost;
	return *this;
}

void PowerFist::attack( void ) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
	return;
}
