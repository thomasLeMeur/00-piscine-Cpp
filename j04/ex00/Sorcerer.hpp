/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 13:24:12 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

#include "Victim.hpp"
#include "Peon.hpp"

class Sorcerer
{

private :
	std::string	_name;
	std::string	_title;

	Sorcerer( void );

public:
	Sorcerer( std::string const name, std::string const title );
	Sorcerer( Sorcerer const & other );
	~Sorcerer( void );

	Sorcerer& operator=( Sorcerer const & other );

	std::string	getName( void ) const;
	std::string	getTitle( void ) const;
	void		polymorph( Victim const & victim ) const;

};

std::ostream& operator<<( std::ostream& stream, Sorcerer const & obj );

#endif // SORCERER_HPP
