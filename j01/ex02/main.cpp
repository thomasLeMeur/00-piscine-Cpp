/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:14:00 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 12:58:24 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main( void )
{
	ZombieEvent event;

	std::cout << "Give the type 'Flex'" << std::endl;
	event.setZombieType("Flex");

	std::cout << "Create 5 flex zombies" << std::endl;

	std::string name = "F1";
	Zombie* f1 = event.newZombie(name);

	name = "F2";
	Zombie* f2 = event.newZombie(name);

	name = "F3";
	Zombie* f3 = event.newZombie(name);

	name = "F4";
	Zombie* f4 = event.newZombie(name);

	name = "F5";
	Zombie* f5 = event.newZombie(name);


	std::cout << "Give the type 'Iron'" << std::endl;
	event.setZombieType("Iron");

	std::cout << "Create 2 iron zombies" << std::endl;

	name = "I1";
	Zombie* i1 = event.newZombie(name);

	name = "I2";
	Zombie* i2 = event.newZombie(name);


	std::cout << "Give the type 'Rand'" << std::endl;
	event.setZombieType("Rand");

	std::cout << "Create 1 rand zombie" << std::endl;

	Zombie* r1 = event.randomChump();


	std::cout << "A big zombie appear" << std::endl;

	Zombie boss("Boss", "Dev");


	std::cout << "All the zombies die" << std::endl;

	delete f1;
	delete f2;
	delete f3;
	delete f4;
	delete f5;
	delete i1;
	delete i2;
	delete r1;

	return (0);
}
