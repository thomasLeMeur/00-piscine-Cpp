/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 19:41:22 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	this->_inventory = new AMateria*[4];
	for (int i = 0 ; i < 4 ; i++)
		this->_inventory[i] = 0;
	return;
}

MateriaSource::MateriaSource( MateriaSource const & other )
{
	this->_inventory = new AMateria*[4];
	for (int i = 0 ; i < 4 ; i++)
		this->_inventory[i] = 0;
	*this = other;
	return;
}

MateriaSource::~MateriaSource( void )
{
	for (int i = 0 ; i < 4 ; i++)
		if (this->_inventory[i] != 0)
			delete this->_inventory[i];
	delete [] this->_inventory;
	return;
}


MateriaSource& MateriaSource::operator=( MateriaSource const & other )
{
	for (int i = 0 ; i < 4 ; i++)
	{
		if (other._inventory[i] == 0)
			this->_inventory[i] = 0;
		else
			this->_inventory[i] = other._inventory[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria( AMateria *m )
{
	for (int i = 0 ; i < 4 ; i++)
		if (this->_inventory[i] == 0)
		{
			this->_inventory[i] = m;
			return;
		}
	return;
}

AMateria* MateriaSource::createMateria( std::string const & type )
{
	for (int i = 0 ; i < 4 ; i++)
		if (this->_inventory[i] != 0 && this->_inventory[i]->getType() == type)
			return this->_inventory[i]->clone();
	return 0;
}
