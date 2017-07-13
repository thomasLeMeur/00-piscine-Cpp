/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 15:11:37 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "SuperMutant.hpp"

SuperMutant::SuperMutant( void ) : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return;
}

SuperMutant::SuperMutant( SuperMutant const & other ) : Enemy(other._hp, other._type)
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return;
}

SuperMutant::~SuperMutant( void )
{
	std::cout << "Aaargh ..." << std::endl;
	return;
}


SuperMutant& SuperMutant::operator=( SuperMutant const & other )
{
	this->_hp = other._hp;
	this->_type = other._type;
	return *this;
}

void SuperMutant::takeDamage( int amount )
{
	if (amount - 3 > 0)
		this->_hp -= amount + 3;
	return;
}
