/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapElement.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppokar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 10:43:21 by ppokar            #+#    #+#             */
/*   Updated: 2017/01/14 21:41:39 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapElement.hpp"

mapElement::mapElement(): _xpos(0), _ypos(0), _dir(0), _symbol('\0') {
}

mapElement::~mapElement() {
}

mapElement::mapElement(double xpos, double ypos, double direction, char symbol ) : _xpos(xpos), _ypos(ypos), _dir(direction), _symbol(symbol) {
}

mapElement::mapElement( mapElement const &obj ) {
	*this = obj;
}

mapElement& mapElement::operator=( mapElement const &obj ) {
	if (this != &obj) {
		this->setXpos(obj.getXpos());
		this->setYpos(obj.getYpos());
		this->setDirection(obj.getDirection());
	}
	return *this;
}

double mapElement::getXpos() const {
	return this->_xpos;
}

double mapElement::getYpos() const {
	return this->_ypos;
}

void mapElement::setXpos( double xpos ) {
	this->_xpos = xpos;
}

void mapElement::setYpos( double ypos ) {
	this->_ypos = ypos;
}


void mapElement::setDirection( double direction ) {
	this->_dir = direction;
}

double mapElement::getDirection( void ) const {
	return this->_dir;
}

char mapElement::getSymbol( void ) const
{
	return this->_symbol;
}
