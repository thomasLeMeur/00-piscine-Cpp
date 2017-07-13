/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 16:22:27 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"

Character::Character( void )
{
	this->_name = "";
	this->_nbap = 40;
	this->_weapon = NULL;
	return;
}

Character::Character( std::string const & name)
{
	this->_name = name;
	this->_nbap = 40;
	this->_weapon = NULL;
	return;
}

Character::Character( Character const & other )
{
	*this = other;
	return;
}

Character::~Character( void )
{
	return;
}

Character& Character::operator=( Character const & other )
{
	this->_name = other._name;
	this->_nbap = other._nbap;
	this->_weapon = other._weapon;
	return *this;
}

std::string const & Character::getName( void ) const
{
	return this->_name;
}

int Character::getNbAP( void ) const
{
	return this->_nbap;
}

AWeapon const * Character::getWeapon( void ) const
{
	return this->_weapon;
}

void Character::equip( AWeapon* weapon )
{
	this->_weapon = weapon;
	return;
}

void Character::recoverAP( void )
{
	this->_nbap = (this->_nbap + 10 > 40 ) ? 40 : this->_nbap + 10;
	return;
}

void Character::attack( Enemy* enemy )
{
	if (enemy != NULL && this->_weapon != NULL && this->_nbap > 0)
	{
		this->_nbap = (this->_nbap - this->_weapon->getAPCost() < 0 ) ? 0 : this->_nbap - this->_weapon->getAPCost();
		std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
		this->_weapon->attack();
		enemy->takeDamage(this->_weapon->getDamage());
		if (enemy->getHP() < 0)
			delete enemy;
	}
	return;
}

std::ostream& operator<<( std::ostream& stream, Character const & obj )
{
	if (obj.getWeapon() == NULL)
		return stream << obj.getName() << " has " << obj.getNbAP() << " AP and is unarmed" << std::endl;
	else
		return stream << obj.getName() << " has " << obj.getNbAP() << " AP and wields a " << obj.getWeapon()->getName() << std::endl;
}
