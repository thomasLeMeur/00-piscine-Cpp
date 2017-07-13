/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 12:46:52 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
	return;
}

ClapTrap::ClapTrap( int const hP, int const mHP, int const eP, int const mEP, int const lvl,
					std::string const name, int const mAD, int const rAD, int const aDR )
{
	srand(time(NULL));
	this->_hitPoints = hP;
	this->_maxHitPoints = mHP;
	this->_energyPoints = eP;
	this->_maxEnergyPoints = mEP;
	this->_level = lvl;
	this->_name = name;
	this->_meleeAttackDamage = mAD;
	this->_rangedAttackDamage = rAD;
	this->_armorDamageReduction = aDR;
	std::cout << "ClapTrap default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap( ClapTrap const & other )
{
	srand(time(NULL));
	*this = other;
	std::cout << "ClapTrap copy constructor called" << std::endl;
	return;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap destructor called" << std::endl;
	return;
}


ClapTrap& ClapTrap::operator=( ClapTrap const & other )
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
	std::cout << "ClapTrap operator= called" << std::endl;
	return *this;
}

void ClapTrap::rangedAttack( std::string const & target )
{
	std::cout << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
	return;
}

void ClapTrap::meleeAttack( std::string const & target )
{
	std::cout << this->_name << " attacks " << target << " at range, causing " << this->_meleeAttackDamage << " points of damage !" << std::endl;
	return;
}

void ClapTrap::beRepaired( unsigned int amount )
{
	this->_hitPoints = ((unsigned int)this->_maxHitPoints < this->_hitPoints + amount) ? this->_maxHitPoints : this->_hitPoints + amount;
	std::cout << this->_name << " has now " << this->_hitPoints << " hit points" << std::endl;

	this->_energyPoints = ((unsigned int)this->_maxEnergyPoints < this->_energyPoints + amount) ? this->_maxEnergyPoints : this->_energyPoints + amount;
	std::cout << this->_name << " has now " << this->_energyPoints << " energy points" << std::endl;
	return;
}

int ClapTrap::takeDamage( unsigned int amount )
{
	amount = ((int)amount - this->_armorDamageReduction <= 0) ? 0 : amount - this->_armorDamageReduction;
	if (amount == 0)
	{
		std::cout << "The attack is too weak to hurt" << std::endl;
		return (0);
	}
	else
	{
		this->_hitPoints = (0 > (int)(this->_hitPoints - amount)) ? 0 : this->_hitPoints - amount;
		if (this->_hitPoints <= 0)
		{
			std::cout << "The attack killed " << this->_name << std::endl;
			return (-1);
		}
		else
		{
			std::cout << this->_name << " still has " << this->_hitPoints << " hit points"<< std::endl;
			return ((int)amount);
		}
	}
}
