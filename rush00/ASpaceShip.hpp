/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpaceShip.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:27:04 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/15 09:42:36 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APSACESHIP_HPP
# define APSACESHIP_HPP

#include "mapElement.hpp"
#include "Weapon.hpp"

class ASpaceShip : public mapElement
{
protected:
	int		_hp;
	Weapon	_weapon;

public:
	ASpaceShip( void );
	ASpaceShip( ASpaceShip const & other );
	virtual ~ASpaceShip( void ) {}

	ASpaceShip& operator=( ASpaceShip const & other );

	int					getHP( void ) const;
	Weapon&				getWeapon( void );
	int					takeDamage( int amount );
	void				setSymbol( char sym );

	virtual ASpaceShip* clone( void ) const = 0;
};

#endif // APSACESHIP_HPP
