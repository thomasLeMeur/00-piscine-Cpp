/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 13:45:13 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AWeapon.hpp"

AWeapon::AWeapon( void )
{
	return;
}

AWeapon::AWeapon( std::string const & name, int apcost, int damage ) : _name(name), _apcost(apcost), _damage(damage)
{
	return;
}

AWeapon::AWeapon( AWeapon const & other )
{
	*this = other;
	return;
}

AWeapon::~AWeapon( void )
{
	return;
}


AWeapon& AWeapon::operator=( AWeapon const & other )
{
	this->_name = other._name;
	this->_damage = other._damage;
	this->_apcost = other._apcost;
	return *this;
}

std::string AWeapon::getName( void ) const
{
	return this->_name;
}

int AWeapon::getAPCost( void ) const
{
	return this->_apcost;
}

int AWeapon::getDamage( void ) const
{
	return this->_damage;
}
