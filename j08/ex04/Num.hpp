/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Num.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/20 12:45:31 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUM_HPP
# define NUM_HPP

#include "AToken.hpp"

class Num : public AToken
{
private :
	Num( Num const & other );
	Num& operator=( Num const & other );

public:
	Num( int val );
	virtual ~Num( void );

	void printType( void );

};
std::ostream & operator<<( std::ostream & stream, Num const & obj );

#endif // NUM_HPP
