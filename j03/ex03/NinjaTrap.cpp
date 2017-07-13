/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 12:48:32 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap( void )
{
	return;
}

NinjaTrap::NinjaTrap( std::string const name ) : ClapTrap(60, 60, 120, 120, 1, name, 60, 5, 0)
{
	std::cout << "NinjaTrap default constructor called" << std::endl;
	return;
}

NinjaTrap::NinjaTrap( NinjaTrap const & other ) : ClapTrap(60, 60, 120, 120, 1, "", 60, 5, 0)
{
	*this = other;
	std::cout << "NinjaTrap copy constructor called" << std::endl;
	return;
}

NinjaTrap::~NinjaTrap( void )
{
	std::cout << "NinjaTrap destructor called" << std::endl;
	return;
}


NinjaTrap& NinjaTrap::operator=( NinjaTrap const & other )
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
	std::cout << "NinjaTrap operator= called" << std::endl;
	return *this;
}

unsigned int NinjaTrap::ninjaShoebox( std::string const & target )
{
	int	arrayOfDamages[6] = {this->_meleeAttackDamage, this->_meleeAttackDamage, this->_meleeAttackDamage, this->_rangedAttackDamage, this->_rangedAttackDamage };
	std::string arrayOfNames[6] = {"snail melee attack", "cum melee attack", "silent awesome attack", "snail ranged attack", "cum ranged attack" };
	void ( NinjaTrap::*arrayOfFunctions[5] )( std::string const & target ) = { &NinjaTrap::meleeAttack, &NinjaTrap::meleeAttack, &NinjaTrap::meleeAttack, &NinjaTrap::rangedAttack, &NinjaTrap::rangedAttack };

	int index = rand() % 6;
	if (index == 5)
	{
		int amount = rand() % ((this->_maxHitPoints > this->_maxEnergyPoints) ? this->_maxHitPoints : this->_maxEnergyPoints);
		std::cout << this->_name << " prefers to restore itself" << std::endl;
		this->beRepaired(amount);
		return (0);
	}
	else if (this->_energyPoints < 25)
	{
		std::cout << this->_name << " has not enough energy to do anything" << std::endl;
		return (0);
	}
	else
	{
		std::cout << this->_name << " performs a " << arrayOfNames[index] << std::endl;
		this->_energyPoints -= 25;
		(this->*arrayOfFunctions[index])(target);
		return (arrayOfDamages[index]);
	}
}
