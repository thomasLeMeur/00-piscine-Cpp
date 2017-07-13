/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppokar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:43:09 by ppokar            #+#    #+#             */
/*   Updated: 2017/01/14 17:02:42 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Shoot_HPP
#define Shoot_HPP

#include "mapElement.hpp"

class Shoot : public mapElement
{
public:
	Shoot();
	virtual ~Shoot();
	Shoot( double xpos, double ypos, double direction, char symbol );
	Shoot( Shoot const &obj );
	Shoot& operator=( Shoot const &obj );
	void printForm();
	Shoot* clone( void ) const;

};

#endif
