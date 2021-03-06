/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 12:26:56 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>

class ScavTrap
{

private :
	int			_hitPoints;
	int			_maxHitPoints;
	int			_energyPoints;
	int			_maxEnergyPoints;
	int			_level;
	std::string	_name;
	int			_meleeAttackDamage;
	int			_rangedAttackDamage;
	int			_armorDamageReduction;

	void	rangedAttack( std::string const & target );
	void	meleeAttack( std::string const & target );
	void	beRepaired( unsigned int amount );

	ScavTrap( void );

public:

	ScavTrap( std::string const name );
	ScavTrap( ScavTrap const & other );
	~ScavTrap( void );

	ScavTrap& operator=( ScavTrap const & other );

	int				takeDamage( unsigned int amount );
	unsigned int	challengeNewcomer( std::string const & target );

};

#endif // SCAVTRAP_HPP
