/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:24:55 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/16 16:04:28 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "CentralBureaucracy.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

std::string nameGenerator( void )
{
	int len = rand() % 10 + 3;
	std::string name = "";

	name += (char)(rand() % 26 + 'A');
	for (int i = 1 ; i < len ; i++)
		name += (char)(rand() % 26 + 'a');

	return name;
}

int main( void )
{
	srand(time(NULL));

	CentralBureaucracy c;
	Bureaucrat **equip = new Bureaucrat*[20];

	for (int i = 0 ; i < 20 ; i++)
	{
		equip[i] = new Bureaucrat(nameGenerator(), rand() % 150 + 1);
		c.feed(*equip[i]);
		std::cout << *equip[i] << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0 ; i < 50 ; i++)
		c.queueUp(nameGenerator());

	c.doBureaucracy();

	for (int i = 0 ; i < 20 ; i++)
		delete equip[i];
	delete [] equip;

	return (0);
}
