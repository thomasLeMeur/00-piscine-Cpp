/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerShip.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/14 13:37:50 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYERSHIP_HPP
# define PLAYERSHIP_HPP

#include "ASpaceShip.hpp"

class PlayerShip : public ASpaceShip
{
public:
	PlayerShip( void );
	PlayerShip( PlayerShip const & other );
	virtual ~PlayerShip( void );

	PlayerShip& operator=( PlayerShip const & other );

	ASpaceShip* clone( void ) const;
	void		printForm( void );

};

#endif // PLAYERSHIP_HPP
