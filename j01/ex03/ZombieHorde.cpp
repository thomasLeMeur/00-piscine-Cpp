/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:58:52 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 12:09:07 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde( int const N ) : _size(N)
{
	srand(time(NULL));

	this->_zombies = new Zombie[N];
	for (int i = 0 ; i < N ; i++)
	{
		unsigned int size = rand() % 17 + 3;
		std::string name = "";
		name += (char)(rand() % 26 + 'A');
		for (unsigned int j = 0 ; j < size ; j ++)
			name += (char)(rand() % 26 + 'a');

		this->_zombies[i].setTypeName("Normal", name);
	}
	return;
}

ZombieHorde::~ZombieHorde( void )
{
	delete [] this->_zombies;
	return;
}

void ZombieHorde::announce( void ) const
{
	for (int i = 0 ; i < this->_size ; i++)
		this->_zombies[i].announce();
	return;
}
