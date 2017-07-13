/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 12:51:25 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SuperTrap.hpp"

SuperTrap::SuperTrap( void )
{
	return;
}

SuperTrap::SuperTrap( std::string const name ) :
		ClapTrap(100, 100, 120, 120, 1, name, 60, 20, 5),
		FragTrap(name), NinjaTrap(name)
{
	std::cout << "SuperTrap default constructor called" << std::endl;
	return;
}

SuperTrap::SuperTrap( SuperTrap const & other ) :
		ClapTrap(100, 100, 120, 120, 1, "", 60, 20, 5),
		FragTrap(""), NinjaTrap("")
{
	*this = other;
	std::cout << "SuperTrap copy constructor called" << std::endl;
	return;
}

SuperTrap::~SuperTrap( void )
{
	std::cout << "SuperTrap destructor called" << std::endl;
	return;
}

SuperTrap& SuperTrap::operator=( SuperTrap const & other )
{
	this->_hitPoints = other._hitPoints;
	this->_maxHitPoints = other._maxHitPoints;
	this->_energyPoints = other._energyPoints;
	this->_maxEnergyPoints = other._maxEnergyPoints;
	this->_level = other._level;
	this->_name = other._name;
	this->_meleeAttackDamage = other._meleeAttackDamage;
	this->_rangedAttackDamage = other._rangedAttackDamage;
	this->_armorDamageReduction = other._armorDamageReduction;
	std::cout << "SuperTrap operator= called" << std::endl;
	return *this;
}
