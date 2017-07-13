/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyShip.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/14 13:37:35 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYSHIP_HPP
# define ENEMYSHIP_HPP

#include "ASpaceShip.hpp"

class EnemyShip : public ASpaceShip
{
public:
	EnemyShip( void );
	EnemyShip( EnemyShip const & other );
	EnemyShip( double xpos, double ypos, double dir, int damage, char symbol);
	virtual ~EnemyShip( void );

	EnemyShip& operator=( EnemyShip const & other );

	ASpaceShip* clone( void ) const;
	void		printForm( void );

};

#endif // ENEMYSHIP_HPP
