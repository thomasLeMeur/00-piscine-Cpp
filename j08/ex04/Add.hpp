/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Add.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/20 12:00:12 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD_HPP
# define ADD_HPP

#include "AToken.hpp"

class Add : public AToken
{
private :
	Add( Add const & other );
	Add& operator=( Add const & other );

public:
	Add( void );
	virtual ~Add( void );

	void printType( void );

};
std::ostream & operator<<( std::ostream & stream, Add const & obj );

#endif // ADD_HPP
