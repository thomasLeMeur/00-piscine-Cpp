/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:58:52 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 11:37:39 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent( void )
{
	return;
}

ZombieEvent::~ZombieEvent( void )
{
	return;
}

void ZombieEvent::setZombieType( std::string type )
{
	this->_type = type;
	return;
}

Zombie* ZombieEvent::newZombie( std::string name)
{
	return new Zombie(this->_type, name);
}

Zombie* ZombieEvent::randomChump( void )
{
	srand(time(NULL));

	unsigned int size = rand() % 17 + 3;

	std::string name = "";
	name += (char)(rand() % 26 + 'A');
	for (unsigned int i = 0 ; i < size ; i ++)
		name += (char)(rand() % 26 + 'a');

	return this->newZombie(name);
}
