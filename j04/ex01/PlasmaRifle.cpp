/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 14:22:20 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle( void ) : AWeapon("Plasma Rifle", 5, 21)
{
	return;
}

PlasmaRifle::PlasmaRifle( PlasmaRifle const & other ) : AWeapon(other._name, other._apcost, other._damage)
{
	return;
}

PlasmaRifle::~PlasmaRifle( void )
{
	return;
}


PlasmaRifle& PlasmaRifle::operator=( PlasmaRifle const & other )
{
	this->_name = other._name;
	this->_damage = other._damage;
	this->_apcost = other._apcost;
	return *this;
}

void PlasmaRifle::attack( void ) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
	return;
}
