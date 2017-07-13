/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 12:46:38 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap
{

protected :
	int			_hitPoints;
	int			_maxHitPoints;
	int			_energyPoints;
	int			_maxEnergyPoints;
	int			_level;
	std::string	_name;
	int			_meleeAttackDamage;
	int			_rangedAttackDamage;
	int			_armorDamageReduction;

	ClapTrap( void );

	void	rangedAttack( std::string const & target );
	void	meleeAttack( std::string const & target );
	void	beRepaired( unsigned int amount );

public:

	ClapTrap(	int const hP, int const mHP, int const eP, int const mEP, int const lvl,
				std::string const name, int const mAD, int const rAD, int const aDR );
	ClapTrap( ClapTrap const & other );
	~ClapTrap( void );

	ClapTrap& operator=( ClapTrap const & other );

	int				takeDamage( unsigned int amount );

};

#endif // CLAPTRAP_HPP
