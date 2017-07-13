/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 17:09:33 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"

class Squad : public ISquad
{
private :
	int				_nbElem;
	ISpaceMarine	**_equip;

public:

	Squad( void );
	Squad( Squad const & other );
	~Squad( void );

	Squad& operator=( Squad const & other );

	int				getCount( void ) const;
	ISpaceMarine*	getUnit( int ind ) const;
	int				push( ISpaceMarine* unit );

};

#endif // SQUAD_HPP
