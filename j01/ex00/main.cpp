/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:14:00 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 12:58:10 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Pony.hpp"

int main( void )
{
	Pony mother(4, 120, 190);
	std::cout << std::endl;

	int nbOfLegs = -1, weight = 20, size = 50;
	std::cout << "Try to create a pony on the heap with " << nbOfLegs << " legs, of " << weight << " kgs and " << size << " cms" << std::endl;
	mother.ponyOnTheHeap(nbOfLegs, weight, size);
	std::cout << std::endl;

	nbOfLegs = 0, weight = 20, size = 50;
	std::cout << "Try to create a pony on the heap with " << nbOfLegs << " legs, of " << weight << " kgs and " << size << " cms" << std::endl;
	mother.ponyOnTheHeap(nbOfLegs, weight, size);
	std::cout << std::endl;

	nbOfLegs = 4, weight = 9, size = 50;
	std::cout << "Try to create a pony on the heap with " << nbOfLegs << " legs, of " << weight << " kgs and " << size << " cms" << std::endl;
	mother.ponyOnTheHeap(nbOfLegs, weight, size);
	std::cout << std::endl;

	nbOfLegs = 4, weight = 310, size = 50;
	std::cout << "Try to create a pony on the heap with " << nbOfLegs << " legs, of " << weight << " kgs and " << size << " cms" << std::endl;
	mother.ponyOnTheHeap(nbOfLegs, weight, size);
	std::cout << std::endl;

	nbOfLegs = 4, weight = 20, size = 10;
	std::cout << "Try to create a pony on the heap with " << nbOfLegs << " legs, of " << weight << " kgs and " << size << " cms" << std::endl;
	mother.ponyOnTheHeap(nbOfLegs, weight, size);
	std::cout << std::endl;

	nbOfLegs = 4, weight = 20, size = 310;
	std::cout << "Try to create a pony on the heap with " << nbOfLegs << " legs, of " << weight << " kgs and " << size << " cms" << std::endl;
	mother.ponyOnTheHeap(nbOfLegs, weight, size);
	std::cout << std::endl;

	//-----------------------------

	nbOfLegs = -1, weight = 20, size = 50;
	std::cout << "Try to create a pony on the stack with " << nbOfLegs << " legs, of " << weight << " kgs and " << size << " cms" << std::endl;
	mother.ponyOnTheStack(nbOfLegs, weight, size);
	std::cout << std::endl;

	nbOfLegs = 0, weight = 20, size = 50;
	std::cout << "Try to create a pony on the stack with " << nbOfLegs << " legs, of " << weight << " kgs and " << size << " cms" << std::endl;
	mother.ponyOnTheStack(nbOfLegs, weight, size);
	std::cout << std::endl;

	nbOfLegs = 4, weight = 9, size = 50;
	std::cout << "Try to create a pony on the stack with " << nbOfLegs << " legs, of " << weight << " kgs and " << size << " cms" << std::endl;
	mother.ponyOnTheStack(nbOfLegs, weight, size);
	std::cout << std::endl;

	nbOfLegs = 4, weight = 310, size = 50;
	std::cout << "Try to create a pony on the stack with " << nbOfLegs << " legs, of " << weight << " kgs and " << size << " cms" << std::endl;
	mother.ponyOnTheStack(nbOfLegs, weight, size);
	std::cout << std::endl;

	nbOfLegs = 4, weight = 20, size = 10;
	std::cout << "Try to create a pony on the stack with " << nbOfLegs << " legs, of " << weight << " kgs and " << size << " cms" << std::endl;
	mother.ponyOnTheStack(nbOfLegs, weight, size);
	std::cout << std::endl;

	nbOfLegs = 4, weight = 20, size = 310;
	std::cout << "Try to create a pony on the stack with " << nbOfLegs << " legs, of " << weight << " kgs and " << size << " cms" << std::endl;
	mother.ponyOnTheStack(nbOfLegs, weight, size);
	std::cout << std::endl;

	//---------------------------

	nbOfLegs = 4, weight = 20, size = 100;
	std::cout << "Try to create a pony on the heap with " << nbOfLegs << " legs, of " << weight << " kgs and " << size << " cms" << std::endl;
	mother.ponyOnTheHeap(nbOfLegs, weight, size);
	std::cout << std::endl;

	nbOfLegs = 4, weight = 20, size = 80;
	std::cout << "Try to create a pony on the stack with " << nbOfLegs << " legs, of " << weight << " kgs and " << size << " cms" << std::endl;
	mother.ponyOnTheStack(nbOfLegs, weight, size);
	std::cout << std::endl;

	return (0);
}
