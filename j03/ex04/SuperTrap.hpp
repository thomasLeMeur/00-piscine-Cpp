/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 12:51:02 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{

public :
	using FragTrap::_hitPoints;
	using FragTrap::_maxHitPoints;
	using NinjaTrap::_energyPoints;
	using NinjaTrap::_maxEnergyPoints;
	using NinjaTrap::_meleeAttackDamage;
	using FragTrap::_rangedAttackDamage;
	using FragTrap::_armorDamageReduction;

	SuperTrap( void );

public:

	SuperTrap( std::string const name );
	SuperTrap( SuperTrap const & other );
	~SuperTrap( void );

	SuperTrap& operator=( SuperTrap const & other );

	using FragTrap::rangedAttack;
	using NinjaTrap::meleeAttack;

	int getLevel( void ) { return this->_level;}
	std::string getName( void ) { return this->_name;}
};

#endif // SUPERTRAP_HPP
