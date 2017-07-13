/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/14 13:06:36 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ASpaceShip.hpp"

class Squad
{
private :
	int			_nbElem;
	ASpaceShip	**_equip;

public:

	Squad( void );
	Squad( Squad const & other );
	virtual ~Squad( void );

	Squad& operator=( Squad const & other );

	int			getCount( void ) const;
	ASpaceShip*	getUnit( int ind ) const;
	int			push( ASpaceShip* unit );
	void		killUnit( ASpaceShip* ship );

};

#endif // SQUAD_HPP
