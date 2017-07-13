/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/14 20:01:46 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include "Shoot.hpp"

class Weapon
{

protected :
	unsigned int	_damage;
	unsigned int	_nbShoots;
	Shoot**			_shoots;
	char			_symbol;

public:

	Weapon( void );
	Weapon( Weapon const & other );
	virtual ~Weapon( void );

	Weapon& operator=( Weapon const & other );

	Shoot*			getShoot( int ind ) const;
	unsigned int	getDamage( void ) const;
	char		getSymbol( void ) const;
	int			getNbShoots( void ) const;
	void		setDamage( int damage );

	void		createShoot( double xpos, double ypos, double dir, int symbol );
	void		shootEnd( Shoot* s );

};

#endif // WEAPON_HPP
