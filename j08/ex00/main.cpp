/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:19:54 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/19 10:29:33 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <array>
#include "easyfind.hpp"

void print( int a) { std::cout << a << std::endl; }

int main( void )
{
	{
		std::cout << "Work on vector of int :" << std::endl << std::endl;

		std::vector<int> tab;
		tab.push_back(10);
		tab.push_back(12);
		tab.push_back(34);
		tab.push_back(25);
		tab.push_back(12);

		for_each(tab.begin(), tab.end(), print);
		std::cout << std::endl;

		std::cout << "Try to have the value 14 : ";
		std::vector<int>::const_iterator val = easyfind(tab, 14);
		std::vector<int>::const_iterator deb = tab.begin();
		if (val == tab.end())
			std::cout << "Not found" << std::endl;
		else
			std::cout << "Value find at the index " << std::distance(deb, val) << std::endl;

		std::cout << "Try to have the value 12 :";
		val = easyfind(tab, 12);
		if (val == tab.end())
			std::cout << "Not found" << std::endl;
		else
			std::cout << "Value find at the index " << std::distance(deb, val) << std::endl;

		std::cout << std::endl << std::endl;
	}
	{
		std::cout << "Work on list of int :" << std::endl << std::endl;

		std::list<int> tab;
		tab.push_back(10);
		tab.push_back(12);
		tab.push_back(34);
		tab.push_back(25);
		tab.push_back(12);

		for_each(tab.begin(), tab.end(), print);
		std::cout << std::endl;

		std::cout << "Try to have the value 14 : ";
		std::list<int>::const_iterator val = easyfind(tab, 14);
		std::list<int>::const_iterator deb = tab.begin();
		if (val == tab.end())
			std::cout << "Not found" << std::endl;
		else
			std::cout << "Value find at the index " << std::distance(deb, val) << std::endl;

		std::cout << "Try to have the value 12 :";
		val = easyfind(tab, 12);
		if (val == tab.end())
			std::cout << "Not found" << std::endl;
		else
			std::cout << "Value find at the index " << std::distance(deb, val) << std::endl;

		std::cout << std::endl << std::endl;
	}

	return 0;
}
