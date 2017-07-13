/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:58:52 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 10:28:30 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Pony.hpp"

Pony::Pony( int const nbOfLegs, int const weight, int const size ) : _nbOfLegs(nbOfLegs), _weight(weight), _size(size)
{
	std::cout << "A pony with " << nbOfLegs << " legs, of " << weight << " kgs and " << size << "cms borned" << std::endl;
	return;
}

Pony::~Pony( void )
{
	std::cout << "A pony with " << this->_nbOfLegs << " legs, of " << this->_weight << " kgs and " << this->_size << "cms died" << std::endl;
	return;
}

void Pony::ponyOnTheHeap( int const nbOfLegs, int const weight, int const size)
{
	if (nbOfLegs < 0) std::cerr << "A pony can't have a negative number of legs" << std::endl;
	else if (nbOfLegs == 0) std::cerr << "I refuse to create a pony without any leg" << std::endl;
	else if (weight < 10) std::cerr << "Please, don't create a pony under 10 kgs" << std::endl;
	else if (weight > 300) std::cerr << "I refuse to create a very fat pony" << std::endl;
	else if (size < 30) std::cerr << "Please, don't create a pony under 30 cms" << std::endl;
	else if (size > 300) std::cerr << "I refuse to create a very big huge pony" << std::endl;
	else
	{
		Pony* pony = new Pony(nbOfLegs, weight, size);
		delete pony;
	}
	return;
}

void Pony::ponyOnTheStack( int const nbOfLegs, int const weight, int const size)
{
	if (nbOfLegs < 0) std::cerr << "A pony can't have a negative number of legs" << std::endl;
	else if (nbOfLegs == 0) std::cerr << "I refuse to create a pony without any leg" << std::endl;
	else if (weight < 10) std::cerr << "Please, don't create a pony under 10 kgs" << std::endl;
	else if (weight > 300) std::cerr << "I refuse to create a very fat pony" << std::endl;
	else if (size < 30) std::cerr << "Please, don't create a pony under 30 cms" << std::endl;
	else if (size > 300) std::cerr << "I refuse to create a very big huge pony" << std::endl;
	else Pony pony(nbOfLegs, weight, size);
	return;
}
