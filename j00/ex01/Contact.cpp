/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:02:16 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/09 15:34:45 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(	int const index, std::string const firstName, std::string const lastName,
					std::string const nickname, std::string const login, std::string const postalAdress,
					std::string const phoneNumber, std::string const birthdayDate,
					std::string const favoriteMeal, std::string const underwearColor,
					std::string const darkestSecret, std::string const emailAdress) :
				_index(index), _firstName(firstName), _lastName(lastName), _nickname(nickname), _login(login),
				_postalAdress(postalAdress), _phoneNumber(phoneNumber), _birthdayDate(birthdayDate),
				_favoriteMeal(favoriteMeal), _underwearColor(underwearColor), _darkestSecret(darkestSecret),
				_emailAdress(emailAdress)
{
	return;
}

Contact::~Contact( void )
{
	return;
}

void Contact::print( void ) const
{
	std::cout << std::endl;
	std::cout << "First name : " << this->_firstName << std::endl;
	std::cout << "Last name : " << this->_lastName << std::endl;
	std::cout << "Nickname : " << this->_nickname << std::endl;
	std::cout << "Login : " << this->_login << std::endl;
	std::cout << "Postal adress : " << this->_postalAdress << std::endl;
	std::cout << "Email adress : " << this->_postalAdress << std::endl;
	std::cout << "Phone number : " << this->_phoneNumber << std::endl;
	std::cout << "Birthday date : " << this->_birthdayDate << std::endl;
	std::cout << "Favorite meal : " << this->_favoriteMeal << std::endl;
	std::cout << "Underwear color : " << this->_underwearColor << std::endl;
	std::cout << "Darkest secret : " << this->_darkestSecret << std::endl;
	std::cout << std::endl;
	return;
}

int Contact::getIndex( void ) const
{
	return this->_index;
}

std::string Contact::getFirstName( void ) const
{
	return this->_firstName;
}

std::string Contact::getLastName( void ) const
{
	return this->_lastName;
}

std::string Contact::getNickname( void ) const
{
	return this->_nickname;
}
