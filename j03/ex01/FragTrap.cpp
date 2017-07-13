/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 12:25:53 by tle-meur         ###   ########.fr       */
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

FragTrap::FragTrap( std::string const name )
{
	srand(time(NULL));
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_name = name;
	this->_meleeAttackDamage = 30;
	this->_rangedAttackDamage = 20;
	this->_armorDamageReduction = 5;
	std::cout << "FragTrap default constructor called" << std::endl;
	return;
}

FragTrap::FragTrap( FragTrap const & other )
{
	srand(time(NULL));
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

void FragTrap::rangedAttack( std::string const & target )
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
	return;
}

void FragTrap::meleeAttack( std::string const & target )
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, causing " << this->_meleeAttackDamage << " points of damage !" << std::endl;
	return;
}

void FragTrap::beRepaired( unsigned int amount )
{
	this->_hitPoints = ((unsigned int)this->_maxHitPoints < this->_hitPoints + amount) ? this->_maxHitPoints : this->_hitPoints + amount;
	std::cout << this->_name << " has now " << this->_hitPoints << " hit points" << std::endl;

	this->_energyPoints = ((unsigned int)this->_maxEnergyPoints < this->_energyPoints + amount) ? this->_maxEnergyPoints : this->_energyPoints + amount;
	std::cout << this->_name << " has now " << this->_energyPoints << " energy points" << std::endl;
	return;
}

int FragTrap::takeDamage( unsigned int amount )
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

unsigned int FragTrap::vaulthunter_dot_exe( std::string const & target )
{
	int	arrayOfDamages[6] = {this->_meleeAttackDamage, this->_meleeAttackDamage, this->_meleeAttackDamage, this->_rangedAttackDamage, this->_rangedAttackDamage };
	std::string arrayOfNames[6] = {"awesome melee attack", "shitty melee attack", "unicorn inutility attack", "awesome ranged attack", "shitty ranged attack" };
	void ( FragTrap::*arrayOfFunctions[5] )( std::string const & target ) = { &FragTrap::meleeAttack, &FragTrap::meleeAttack, &FragTrap::meleeAttack, &FragTrap::rangedAttack, &FragTrap::rangedAttack };

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
