/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 17:23:54 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Squad.hpp"

Squad::Squad( void )
{
	this->_nbElem = 0;
	this->_equip = new ISpaceMarine*[0];
	return;
}

Squad::Squad( Squad const & other )
{
	this->_nbElem = 0;
	*this = other;
	return;
}

Squad::~Squad( void )
{
	for (int i = 0 ; i < this->_nbElem ; i++)
		if (this->_equip[i] != 0)
			delete this->_equip[i];
	delete [] this->_equip;
	return;
}

Squad& Squad::operator=( Squad const & other )
{
	if (this->_nbElem > 0)
	{
		for (int i = 0 ; i < this->_nbElem ; i++)
			if (this->_equip[i] != 0)
				delete this->_equip[i];
		delete [] this->_equip;
	}

	this->_nbElem = other._nbElem;
	this->_equip = new ISpaceMarine*[this->_nbElem];
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

ISpaceMarine* Squad::getUnit( int ind ) const
{
	if (ind >= this->_nbElem)
		return 0;
	else
		return this->_equip[ind];
}

int Squad::push( ISpaceMarine* unit )
{
	if (unit == 0)
		return this->_nbElem;
	for (int i = 0 ; i < this->_nbElem ; i++)
		if (unit == this->_equip[i])
			return this->_nbElem;

	ISpaceMarine** tmp = new ISpaceMarine*[this->_nbElem + 1];
	for (int i = 0 ; i < this->_nbElem ; i++)
		tmp[i] = this->_equip[i];
	delete [] this->_equip;
	this->_equip = tmp;

	this->_equip[this->_nbElem] = unit;
	return ++this->_nbElem;
}
