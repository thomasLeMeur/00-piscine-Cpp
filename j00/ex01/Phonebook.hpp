/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:02:58 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/09 15:36:19 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
private :

	unsigned int	_contactNb;
	Contact			*_contacts[8];

public :

	Phonebook( void );
	~Phonebook( void );

	void			print( void ) const;
	int				add(	std::string const firstName, std::string const lastName, std::string const nickname,
							std::string const login, std::string const postalAdress, std::string const phoneNumber,
							std::string const birthdayDate, std::string const favoriteMeal,
							std::string const underwearColor, std::string const darkestSecret, std::string const emailAdress);
	bool			printContact( int const index) const;
	unsigned int	getContactNb( void ) const;

};

#endif // PHONEBOOK_HPP
