/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:26:10 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 17:42:11 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_HPP
# define ISQUAD_HPP

#include "ISpaceMarine.hpp"

class ISquad
{
public:
	virtual ~ISquad( void ) {}

	virtual int getCount( void ) const = 0;
	virtual ISpaceMarine* getUnit( int ) const = 0;
	virtual int push( ISpaceMarine* ) = 0;

};

#endif // ISQUAD_HPP
