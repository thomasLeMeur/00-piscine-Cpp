/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 12:26:25 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	return;
}

FragTrap::FragTrap( std::string const name ) : ClapTrap(100, 100, 100, 100, 1, name, 30, 20, 5)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	return;
}

FragTrap::FragTrap( FragTrap const & other ) : ClapTrap(100, 100, 100, 100, 1, "", 30, 20, 5)
{
	*this = other;
	std::cout << "FragTrap copy constructor called" << std::endl;
	return;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap destructor called" << std::endl;
	return;
}


FragTrap& FragTrap::operator=( FragTrap const & other )
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
	std::cout << "FragTrap operator= called" << std::endl;
	return *this;
}

unsigned int FragTrap::vaulthunter_dot_exe( std::string const & target )
{
	int	arrayOfDamages[6] = {this->_meleeAttackDamage, this->_meleeAttackDamage, this->_meleeAttackDamage, this->_rangedAttackDamage, this->_rangedAttackDamage };
	std::string arrayOfNames[6] = {"awesome melee attack", "shitty melee attack", "unicorn inutility attack", "awesome ranged attack", "shitty ranged attack" };
	void ( ClapTrap::*arrayOfFunctions[5] )( std::string const & target ) = { &ClapTrap::meleeAttack, &ClapTrap::meleeAttack, &ClapTrap::meleeAttack, &ClapTrap::rangedAttack, &ClapTrap::rangedAttack };

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
