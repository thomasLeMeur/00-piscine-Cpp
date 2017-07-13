/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:14:00 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 12:58:34 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main( void )
{
	std::cout << "Create a hord of 17 zombies" << std::endl;
	ZombieHorde horde(17);

	std::cout << std::endl;
	std::cout << "Re announce everybody" << std::endl;
	horde.announce();
	std::cout << std::endl;

	return (0);
}
