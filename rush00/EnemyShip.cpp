/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyShip.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/15 09:41:25 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnemyShip.hpp"
#include "EnemyWeapon.hpp"

EnemyShip::EnemyShip( void ) : ASpaceShip()
{
	this->_hp = 1;
	this->_weapon = EnemyWeapon();
	this->_symbol = '~';
	return;
}

EnemyShip::EnemyShip( EnemyShip const & other ) : ASpaceShip()
{
	*this = other;
	return;
}

EnemyShip::EnemyShip( double xpos, double ypos, double dir, int damage, char symbol) : ASpaceShip()
{
	this->_hp = 1;
	this->_weapon = EnemyWeapon();
	this->_weapon.setDamage(damage);
	this->_xpos = xpos;
	this->_ypos = ypos;
	this->_dir = dir;
	this->_symbol = symbol;
}


EnemyShip::~EnemyShip( void )
{
	return;
}

EnemyShip& EnemyShip::operator=( EnemyShip const & other )
{
	this->_dir = other._dir;
	this->_hp = other._hp;
	this->_weapon = other._weapon;
	return *this;
}

ASpaceShip* EnemyShip::clone( void ) const
{
	return new EnemyShip(*this);
}

void EnemyShip::printForm(){}
