/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 16:21:15 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy( void )
{
	return;
}

Enemy::Enemy( int hp, std::string const & type ) : _hp(hp), _type(type)
{
	return;
}

Enemy::Enemy( Enemy const & other )
{
	*this = other;
	return;
}

Enemy::~Enemy( void )
{
	return;
}


Enemy& Enemy::operator=( Enemy const & other )
{
	this->_hp = other._hp;
	this->_type = other._type;
	return *this;
}

std::string const & Enemy::getType( void ) const
{
	return this->_type;
}

int Enemy::getHP( void ) const
{
	return this->_hp;
}

void Enemy::takeDamage( int amount )
{
	if (amount >= 0)
		this->_hp -= amount;
	return;
}
