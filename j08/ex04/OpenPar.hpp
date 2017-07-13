/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenPar.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/20 12:01:31 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENPAR_HPP
# define OPENPAR_HPP

#include "AToken.hpp"

class OpenPar : public AToken
{
private :
	OpenPar( OpenPar const & other );
	OpenPar& operator=( OpenPar const & other );

public:
	OpenPar( void );
	virtual ~OpenPar( void );

	void printType( void );

};
std::ostream & operator<<( std::ostream & stream, OpenPar const & obj );

#endif // OPENPAR_HPP
