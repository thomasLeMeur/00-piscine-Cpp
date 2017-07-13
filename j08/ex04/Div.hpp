/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Div.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/20 12:00:34 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIV_HPP
# define DIV_HPP

#include "AToken.hpp"

class Div : public AToken
{
private :
	Div( Div const & other );
	Div& operator=( Div const & other );

public:
	Div( void );
	virtual ~Div( void );

	void printType( void );

};
std::ostream & operator<<( std::ostream & stream, Div const & obj );

#endif // DIV_HPP
