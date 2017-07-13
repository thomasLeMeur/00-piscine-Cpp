/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerShip.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/15 09:43:36 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlayerShip.hpp"
#include "PlayerWeapon.hpp"

PlayerShip::PlayerShip( void ) : ASpaceShip()
{
	this->_hp = 100;
	this->_weapon = PlayerWeapon();
	this->_symbol = '$';
	return;
}

PlayerShip::PlayerShip( PlayerShip const & other ) : ASpaceShip()
{
	*this = other;
	return;
}

PlayerShip::~PlayerShip( void )
{
	return;
}


PlayerShip& PlayerShip::operator=( PlayerShip const & other )
{
	this->_dir = other._dir;
	this->_hp = other._hp;
	this->_weapon = other._weapon;
	return *this;
}

ASpaceShip* PlayerShip::clone( void ) const
{
	return new PlayerShip(*this);
}

void PlayerShip::printForm(){}
