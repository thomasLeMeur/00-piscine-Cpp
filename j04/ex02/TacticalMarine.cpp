/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 17:32:20 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine( void )
{
	std::cout << "Tactical Marine ready for battle" << std::endl;
	return;
}

TacticalMarine::TacticalMarine( TacticalMarine const & other )
{
	std::cout << "Tactical Marine ready for battle" << std::endl;
	*this = other;
	return;
}

TacticalMarine::~TacticalMarine( void )
{
	std::cout << "Aaargh ..." << std::endl;
	return;
}


TacticalMarine& TacticalMarine::operator=( TacticalMarine const & other )
{
	(void)other;
	return *this;
}

ISpaceMarine* TacticalMarine::clone( void ) const
{
	return new TacticalMarine(*this);
}

void TacticalMarine::battleCry( void ) const
{
	std::cout << "For the holy PLOT !" << std::endl;
	return;
}

void TacticalMarine::rangedAttack( void ) const
{
	std::cout << "* attacks with bolter *" << std::endl;
	return;
}

void TacticalMarine::meleeAttack( void ) const
{
	std::cout << "* attacks with chainsword *" << std::endl;
	return;
}
