/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppokar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:42:58 by ppokar            #+#    #+#             */
/*   Updated: 2017/01/14 17:04:19 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shoot.hpp"

Shoot::Shoot(): mapElement() {
}

Shoot::~Shoot() {
}

Shoot::Shoot(double xpos, double ypos, double direction, char symbol ) : mapElement( xpos, ypos, direction, symbol ) {
}

Shoot::Shoot( Shoot const &obj ) {
	*this = obj;
}

Shoot& Shoot::operator=( Shoot const &obj ) {
	if (this != &obj) {
		this->setXpos(obj.getXpos());
		this->setYpos(obj.getYpos());
		this->setDirection(obj.getDirection());
	}
	return *this;
}

void Shoot::printForm( void ) {
}

Shoot* Shoot::clone( void ) const {
	return new Shoot(*this);
}
