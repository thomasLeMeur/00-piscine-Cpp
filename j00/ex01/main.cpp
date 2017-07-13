/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:22:17 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/09 15:37:44 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Phonebook.hpp"

bool isNumber( std::string& num )
{
	for (unsigned int i = 0 ; i < num.size() ; i++)
		if (!(num.c_str()[i] >= '0' && num.c_str()[i] <= '9'))
			return false;
	return true;
}

void searchContact( Phonebook& book )
{
	if ( book.getContactNb() > 0 )
		while ( true )
		{
			book.print();

			std::string index;
			std::cout << "Index of wanted contact : ";
			getline(std::cin, index);

			if ( isNumber(index) == false )
				std::cout << "Please enter a number" << std::endl;

			else if ( book.printContact(std::stoi(index)) == true )
				break;
		}
	else
		std::cout << "The phone book is empty." << std::endl;
	return;
}

void addContact( Phonebook& book)
{
	std::string args[11];
	std::string wanteds[11] = {"first name", "last name", "nickname", "login", "postal adress", "email adress",
							"phone number", "birthday date", "favorite meal", "underwear color", "darkest secret"};

	while ( true )
	{
		for (unsigned int i = 0 ; i < 11 ; i++)
		{
			std::cout << "Please enter your " << wanteds[i] << " (I trust in your honesty) : ";
			getline(std::cin, args[i]);
		}

		if ( book.add(args[0], args[1], args[2], args[3], args[4], args[6], args[7], args[8], args[9], args[10], args[5]) >= 0 )
			break;
	}
}

int main( void )
{
	Phonebook book;

	while ( true )
	{
		std::string cmd;

		std::cout << "$>";
		getline(std::cin, cmd);

		if ( cmd == "EXIT" )
			break;
		else if ( cmd == "ADD" )
			addContact(book);
		else if ( cmd == "SEARCH" )
			searchContact(book);
		else
			std::cout << "Please, enter a command in 'EXIT / ADD / SEARCH'" << std::endl;
	}
}
