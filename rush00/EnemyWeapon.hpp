/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyWeapon.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/14 13:22:52 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYWEAPON_HPP
# define ENEMYWEAPON_HPP

#include "Weapon.hpp"

class EnemyWeapon : public Weapon
{
public:

	EnemyWeapon( void );
	EnemyWeapon( EnemyWeapon const & other );
	virtual ~EnemyWeapon( void );

	EnemyWeapon& operator=( EnemyWeapon const & other );

	//void printForm( void );

};

#endif // ENEMYWEAPON_HPP
