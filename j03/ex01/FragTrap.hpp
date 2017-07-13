/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 12:24:32 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

class FragTrap
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

	FragTrap( void );

public:

	FragTrap( std::string const name );
	FragTrap( FragTrap const & other );
	~FragTrap( void );

	FragTrap& operator=( FragTrap const & other );

	int				takeDamage( unsigned int amount );
	unsigned int	vaulthunter_dot_exe( std::string const & target );

};

#endif // FRAGTRAP_HPP
