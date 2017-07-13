/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerWeapon.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/14 13:18:35 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYERWEAPON_HPP
# define PLAYERWEAPON_HPP

#include "Weapon.hpp"

class PlayerWeapon : public Weapon
{
public:

	PlayerWeapon( void );
	PlayerWeapon( PlayerWeapon const & other );
	virtual ~PlayerWeapon( void );

	PlayerWeapon& operator=( PlayerWeapon const & other );

	//void printForm( void );

};

#endif // PLAYERWEAPON_HPP
