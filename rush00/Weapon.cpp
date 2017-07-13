/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/15 09:36:06 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon( void )
{
	this->_nbShoots = 0;
	this->_shoots = 0;
	this->_symbol = 'W';
	return;
}

Weapon::Weapon( Weapon const & other )
{
	this->_nbShoots = 0;
	this->_shoots = 0;
	*this = other;
	return;
}

Weapon::~Weapon( void )
{
	for (unsigned int i = 0 ; i < this->_nbShoots ; i++)
		if (this->_shoots[i] != 0)
			delete this->_shoots[i];
	if (this->_shoots != 0)
		delete [] this->_shoots;
	return;
}

Weapon& Weapon::operator=( Weapon const & other )
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
	this->_symbol = other._symbol;
	return *this;
}

Shoot* Weapon::getShoot( int ind ) const
{
	if (ind >= 0 && ind < (int)this->_nbShoots)
		return this->_shoots[ind];
	else
		return 0;
}

unsigned int Weapon::getDamage( void ) const
{
	return this->_damage;
}

void Weapon::setDamage( int damage )
{
	this->_damage = damage;
	return;
}

int Weapon::getNbShoots( void ) const
{
	return this->_nbShoots;
}

void Weapon::shootEnd( Shoot* s)
{
	if (s == 0)
		return;

	Shoot** tmp = new Shoot*[this->_nbShoots - 1];
	unsigned int ind;
	int find = 0;
	for (ind = 0 ; ind < this->_nbShoots ; ind++)
	{
		if (this->_shoots[ind] != s)
			tmp[ind - find] = this->_shoots[ind];
		else
			find = 1;
	}
	delete s;
	delete [] this->_shoots;
	this->_shoots = tmp;
	this->_nbShoots--;
	return;
}

void Weapon::createShoot( double xpos, double ypos, double dir, int symbol )
{
	Shoot** tmp = new Shoot*[this->_nbShoots + 1];
	for (unsigned int i = 0 ; i < this->_nbShoots ; i++)
		tmp[i] = this->_shoots[i];
	delete [] this->_shoots;

	tmp[this->_nbShoots++] = new Shoot(xpos, ypos + dir, dir + ((dir < 0) ? -1 : 1), symbol);
	this->_shoots = tmp;
	return;
}

char Weapon::getSymbol( void ) const
{
	return this->_symbol;
}
