/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 12:29:14 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	return;
}

ScavTrap::ScavTrap( std::string const name ) : ClapTrap(100, 100, 50, 50, 1, name, 20, 15, 2)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap( ScavTrap const & other ) : ClapTrap(100, 100, 50, 50, 1, "", 20, 15, 2)
{
	*this = other;
	std::cout << "ScavTrap copy constructor called" << std::endl;
	return;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap destructor called" << std::endl;
	return;
}


ScavTrap& ScavTrap::operator=( ScavTrap const & other )
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
	std::cout << "ScavTrap operator= called" << std::endl;
	return *this;
}

unsigned int ScavTrap::challengeNewcomer( std::string const & target )
{
	int	arrayOfDamages[6] = {this->_meleeAttackDamage, this->_meleeAttackDamage, this->_meleeAttackDamage, this->_rangedAttackDamage, this->_rangedAttackDamage };
	std::string arrayOfNames[6] = {"middle melee attack", "stinky melee attack", "butterfly inutility attack" , "middle ranged attack", "stinky ranged attack" };
	void ( ScavTrap::*arrayOfFunctions[5] )( std::string const & target ) = { &ScavTrap::meleeAttack, &ScavTrap::meleeAttack, &ScavTrap::meleeAttack, &ScavTrap::rangedAttack, &ScavTrap::rangedAttack };

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
