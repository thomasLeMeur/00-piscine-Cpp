/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpaceShip.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:50:36 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/15 09:43:01 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ASpaceShip.hpp"

ASpaceShip::ASpaceShip( void ) : mapElement(), _hp(0)
{
	this->_dir = 0;
	return;
}

ASpaceShip::ASpaceShip( ASpaceShip const & other ) : mapElement()
{
	*this = other;
	return;
}

ASpaceShip& ASpaceShip::operator=( ASpaceShip const & other )
{
	this->_hp = other._hp;
	this->_dir = other._dir;
	this->_weapon = other._weapon;
	return *this;
}

int	ASpaceShip::getHP( void ) const
{
	return this->_hp;
}

Weapon&	ASpaceShip::getWeapon( void )
{
	return this->_weapon;
}

int ASpaceShip::takeDamage( int amount )
{
	this->_hp -= amount;
	return this->_hp;
}

void ASpaceShip::setSymbol( char sym )
{
	this->_symbol = sym;
	return;
}
