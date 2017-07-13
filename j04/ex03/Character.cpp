/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 19:40:02 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"

Character::Character( void )
{
	return;
}

Character::Character( std::string const & name ) : _name(name)
{
	this->_inventory = new AMateria*[4];
	for (int i = 0 ; i < 4 ; i++)
		this->_inventory[i] = 0;
	return;
}

Character::Character( Character const & other )
{
	this->_inventory = new AMateria*[4];
	for (int i = 0 ; i < 4 ; i++)
		this->_inventory[i] = 0;
	*this = other;
	return;
}

Character::~Character( void )
{
	for (int i = 0 ; i < 4 ; i++)
		if (this->_inventory[i] != 0)
			delete this->_inventory[i];
	delete [] this->_inventory;
	return;
}


Character& Character::operator=( Character const & other )
{
	for (int i = 0 ; i < 4 ; i++)
	{
		if (other._inventory[i] == 0)
			this->_inventory[i] = 0;
		else
			this->_inventory[i] = other._inventory[i]->clone();
	}
	return *this;
}

std::string const & Character::getName( void ) const
{
	return this->_name;
}

void Character::equip( AMateria *m )
{
	for (int i = 0 ; i < 4 ; i++)
		if (this->_inventory[i] == 0)
		{
			this->_inventory[i] = m;
			return;
		}
	return;
}

void Character::unequip( int idx )
{
	if (idx >= 0 && idx < 4)
		this->_inventory[idx] = 0;
	return;
}

void Character::use( int idx, ICharacter& target )
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != 0)
		this->_inventory[idx]->use(target);
	return;
}
