/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:21:10 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/09 15:35:59 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Phonebook.hpp"

Phonebook::Phonebook( void )
{
	this->_contactNb = 0;
	for (unsigned int i = 0 ; i < 8 ; i++)
		this->_contacts[i] = NULL;
	return;
}

Phonebook::~Phonebook( void )
{
	this->_contactNb = 0;
	for (unsigned int i = 0 ; i < 8 ; i++)
		if ( this->_contacts[i] != NULL )
		{
			delete this->_contacts[i];
			this->_contacts[i] = NULL;
		}
	return;
}

unsigned int Phonebook::getContactNb( void ) const
{
	return this->_contactNb;
}

int Phonebook::add(std::string const firstName, std::string const lastName, std::string const nickname,
					std::string const login, std::string const postalAdress, std::string const phoneNumber,
					std::string const birthdayDate, std::string const favoriteMeal,
					std::string const underwearColor, std::string const darkestSecret, std::string const emailAdress)
{
	if ( this->_contactNb >= 8 )
	{
		std::cout << "The phone book is full, sorry !" << std::endl;
		return (1);
	}
	else if (firstName != "" && lastName != "" && nickname != "" && login != "" && postalAdress != ""
		&& phoneNumber != "" && birthdayDate != "" && favoriteMeal != "" && underwearColor != ""
		&& darkestSecret != "" && emailAdress != "")
	{
		for (unsigned int i = 0 ; i < 8 ; i++)
			if ( this->_contacts[i] != NULL && this->_contacts[i]->getFirstName() == firstName
				&& this->_contacts[i]->getLastName() == lastName && this->_contacts[i]->getNickname() == nickname)
			{
				std::cout << "This contact already exists !" << std::endl;
				return (-2);
			}

		for (unsigned int i = 0 ; i < 8 ; i++)
			if ( this->_contacts[i] == NULL )
			{
				this->_contacts[i] = new Contact(i, firstName, lastName, nickname, login, postalAdress,
												phoneNumber, birthdayDate, favoriteMeal, underwearColor,
												darkestSecret, emailAdress);
				this->_contactNb++;
				return (0);
			}
	}
	return (-1);
}

bool Phonebook::printContact( int const index ) const
{
	if ( index < 0 || index > 7 )
		std::cout << "The index of the contact to print has to be between 0 and 8 exclusive." << std::endl;
	else if ( this->_contacts[index] != NULL)
	{
		this->_contacts[index]->print();
		return true;
	}
	else
		std::cout << "The contact doesn't exist." << std::endl;
	return false;
}

void Phonebook::print( void ) const
{
	std::cout << std::endl;
	std::cout << "   Index  |First name| Last name| Nickname |" << std::endl;
	for (unsigned i = 0 ; i < 8 ; i++)
		if ( this->_contacts[i] != NULL )
		{
			std::string index = std::to_string(this->_contacts[i]->getIndex());
			std::string firstName = this->_contacts[i]->getFirstName();
			std::string lastName = this->_contacts[i]->getLastName();
			std::string nickname = this->_contacts[i]->getNickname();

			if ( index.size() > 10 )
				index = index.substr(0, 9) + ".";
			if ( firstName.size() > 10 )
				firstName = firstName.substr(0, 9) + ".";
			if ( lastName.size() > 10 )
				lastName = lastName.substr(0, 9) + ".";
			if ( nickname.size() > 10 )
				nickname = nickname.substr(0, 9) + ".";

			std::cout << std::setiosflags(std::ios::right);
			std::cout << std::setw(10) << index << "|" << std::setw(10) << firstName << "|" << std::setw(10) << lastName << "|" << std::setw(10) << nickname << "|" << std::endl;
			std::cout << std::resetiosflags(std::ios::right);
		}
	std::cout << std::endl;
	return;
}
