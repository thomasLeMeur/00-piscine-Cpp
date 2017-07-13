/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:02:58 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/09 15:35:07 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
private :

	int const			_index;
	std::string const	_firstName;
	std::string	const	_lastName;
	std::string	const	_nickname;
	std::string	const	_login;
	std::string	const	_postalAdress;
	std::string	const	_emailAdress;
	std::string	const	_phoneNumber;
	std::string	const	_birthdayDate;
	std::string	const	_favoriteMeal;
	std::string	const	_underwearColor;
	std::string	const	_darkestSecret;

public :

	Contact(	int const index, std::string const firstName, std::string const lastName,
				std::string const nickname, std::string const login, std::string const postalAdress,
				std::string const phoneNumber, std::string const birthdayDate,
				std::string const favoriteMeal, std::string const underwearColor,
				std::string const darkestSecret, std::string const emailAdress);
	~Contact( void );

	void		print( void ) const;
	int			getIndex( void ) const;
	std::string	getFirstName( void ) const;
	std::string	getLastName( void ) const;
	std::string	getNickname( void ) const;

};

#endif // CONTACT_HPP
