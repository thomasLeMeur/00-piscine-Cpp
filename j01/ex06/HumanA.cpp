/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:58:52 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 13:32:32 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _weapon(weapon), _name(name)
{
	return;
}

HumanA::~HumanA( void )
{
	return;
}

void HumanA::attack( void ) const
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
	return;
}
