/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerWeapon.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/14 19:59:40 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PlayerWeapon.hpp"

PlayerWeapon::PlayerWeapon( void )
{
	this->_damage = 50;
	this->_nbShoots = 0;
	this->_shoots = 0;
	this->_symbol = '^';
	return;
}

PlayerWeapon::PlayerWeapon( PlayerWeapon const & other )
{
	this->_nbShoots = 0;
	this->_shoots = 0;
	*this = other;
	return;
}

PlayerWeapon::~PlayerWeapon( void )
{
	return;
}

PlayerWeapon& PlayerWeapon::operator=( PlayerWeapon const & other )
{
	if (this->_shoots != 0)
	{
		for (unsigned int i = 0 ; i < this->_nbShoots ; i++)
			if (this->_shoots[i] != 0)
				delete this->_shoots[i];
		delete [] this->_shoots;
	}

	this->_shoots = new Shoot*[other._nbShoots];
	for (unsigned int i = 0 ; i < other._nbShoots ; i++)
	{
		if (other._shoots[i] == 0)
			this->_shoots[i] = 0;
		else
			this->_shoots[i] = other._shoots[i]->clone();
	}
	this->_damage = other._damage;
	this->_nbShoots = other._nbShoots;
	return *this;
}
