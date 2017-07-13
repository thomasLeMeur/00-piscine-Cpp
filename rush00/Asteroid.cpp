/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/15 09:44:06 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Asteroid.hpp"
#include "EnemyWeapon.hpp"

Asteroid::Asteroid( void ) : ASpaceShip()
{
	this->_hp = 10;
	this->_weapon = EnemyWeapon();
	this->_weapon.setDamage(0);
	this->_symbol = 'A';
	return;
}

Asteroid::Asteroid( Asteroid const & other ) : ASpaceShip()
{
	*this = other;
	return;
}

Asteroid::~Asteroid( void )
{
	return;
}

Asteroid& Asteroid::operator=( Asteroid const & other )
{
	this->_dir = other._dir;
	this->_hp = other._hp;
	this->_weapon = other._weapon;
	return *this;
}

ASpaceShip* Asteroid::clone( void ) const
{
	return new Asteroid(*this);
}

void Asteroid::printForm(){}
