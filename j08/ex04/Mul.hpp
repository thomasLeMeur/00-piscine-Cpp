/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mul.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/20 12:00:51 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUL_HPP
# define MUL_HPP

#include "AToken.hpp"

class Mul : public AToken
{
private :
	Mul( Mul const & other );
	Mul& operator=( Mul const & other );

public:
	Mul( void );
	virtual ~Mul( void );

	void printType( void );

};
std::ostream & operator<<( std::ostream & stream, Mul const & obj );

#endif // MUL_HPP
