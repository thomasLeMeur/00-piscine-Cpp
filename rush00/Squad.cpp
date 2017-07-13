/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/15 09:35:50 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Squad.hpp"

Squad::Squad( void )
{
	this->_nbElem = 0;
	this->_equip = 0;
	return;
}

Squad::Squad( Squad const & other )
{
	this->_nbElem = 0;
	this->_equip = 0;
	*this = other;
	return;
}

Squad::~Squad( void )
{
	for (int i = 0 ; i < this->_nbElem ; i++)
		if (this->_equip[i] != 0)
			delete this->_equip[i];
	if (this->_equip != 0)
		delete [] this->_equip;
	return;
}

Squad& Squad::operator=( Squad const & other )
{
	if (this->_equip != 0)
	{
		for (int i = 0 ; i < this->_nbElem ; i++)
			if (this->_equip[i] != 0)
				delete this->_equip[i];
		delete [] this->_equip;
	}

	this->_nbElem = other._nbElem;
	this->_equip = new ASpaceShip*[this->_nbElem];
	for (int i = 0 ; i < this->_nbElem ; i++)
	{
		if (other._equip[i] == 0)
			this->_equip[i] = 0;
		else
			this->_equip[i] = other._equip[i]->clone();
	}
	return *this;
}

int Squad::getCount( void ) const
{
	return this->_nbElem;
}

ASpaceShip* Squad::getUnit( int ind ) const
{
	if (ind >= this->_nbElem)
		return 0;
	else
		return this->_equip[ind];
}

int Squad::push( ASpaceShip* unit )
{
	if (unit == 0)
		return this->_nbElem;
	for (int i = 0 ; i < this->_nbElem ; i++)
		if (unit == this->_equip[i])
			return this->_nbElem;

	ASpaceShip** tmp = new ASpaceShip*[this->_nbElem + 1];
	for (int i = 0 ; i < this->_nbElem ; i++)
		tmp[i] = this->_equip[i];
	delete [] this->_equip;
	this->_equip = tmp;

	this->_equip[this->_nbElem] = unit;
	return ++this->_nbElem;
}

void Squad::killUnit( ASpaceShip * ship )
{
	if (ship == 0)
		return;
	ASpaceShip** tmp = new ASpaceShip*[this->_nbElem - 1];
	int ind;
	int find = 0;
	for (ind = 0 ; ind < this->_nbElem ; ind++)
	{
		if (this->_equip[ind] != ship)
			tmp[ind - find] = this->_equip[ind];
		else
			find = 1;
	}
	delete ship;
	delete [] this->_equip;
	this->_equip = tmp;
	this->_nbElem--;
	return;
}
