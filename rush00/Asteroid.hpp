/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/14 16:59:26 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROID_HPP
# define ASTEROID_HPP

#include "ASpaceShip.hpp"

class Asteroid : public ASpaceShip
{
public:
	Asteroid( void );
	Asteroid( Asteroid const & other );
	virtual ~Asteroid( void );

	Asteroid& operator=( Asteroid const & other );

	ASpaceShip* clone( void ) const;
	void		printForm( void );

};

#endif // ASTEROID_HPP
