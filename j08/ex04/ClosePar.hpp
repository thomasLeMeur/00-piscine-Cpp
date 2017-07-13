/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClosePar.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/20 12:02:20 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLOSEPAR_HPP
# define CLOSEPAR_HPP

#include "AToken.hpp"

class ClosePar : public AToken
{
private :
	ClosePar( ClosePar const & other );
	ClosePar& operator=( ClosePar const & other );

public:
	ClosePar( void );
	virtual ~ClosePar( void );

	void printType( void );

};
std::ostream & operator<<( std::ostream & stream, ClosePar const & obj );

#endif // CLOSEPAR_HPP
