/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 17:44:09 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator( void )
{
	std::cout << "* teleports from space *" << std::endl;
	return;
}

AssaultTerminator::AssaultTerminator( AssaultTerminator const & other )
{
	std::cout << "* teleports from space *" << std::endl;
	*this = other;
	return;
}

AssaultTerminator::~AssaultTerminator( void )
{
	std::cout << "I’ll be back ..." << std::endl;
	return;
}


AssaultTerminator& AssaultTerminator::operator=( AssaultTerminator const & other )
{
	(void)other;
	return *this;
}

ISpaceMarine* AssaultTerminator::clone( void ) const
{
	return new AssaultTerminator(*this);
}

void AssaultTerminator::battleCry( void ) const
{
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
	return;
}

void AssaultTerminator::rangedAttack( void ) const
{
	std::cout << "* does nothing *" << std::endl;
	return;
}

void AssaultTerminator::meleeAttack( void ) const
{
	std::cout << "* attacks with chainfists *" << std::endl;
	return;
}
