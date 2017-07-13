/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenPar.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/20 14:00:01 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OpenPar.hpp"

OpenPar::OpenPar( void ) : AToken(0, "")
{
	return;
}

OpenPar::~OpenPar( void )
{
	return;
}

void OpenPar::printType( void )
{
	return;
}

std::ostream & operator<<( std::ostream & stream, OpenPar const & obj )
{
	return stream << std::left << "ParOpen";
}
