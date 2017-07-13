/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 15:17:00 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RadScorpion.hpp"

RadScorpion::RadScorpion( void ) : Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
	return;
}

RadScorpion::RadScorpion( RadScorpion const & other ) : Enemy(other._hp, other._type)
{
	std::cout << "* click click click *" << std::endl;
	return;
}

RadScorpion::~RadScorpion( void )
{
	std::cout << "* SPROTCH *" << std::endl;
	return;
}


RadScorpion& RadScorpion::operator=( RadScorpion const & other )
{
	this->_hp = other._hp;
	this->_type = other._type;
	return *this;
}
