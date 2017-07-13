/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClosePar.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/20 13:59:42 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClosePar.hpp"

ClosePar::ClosePar( void ) : AToken(0, "")
{
	return;
}

ClosePar::~ClosePar( void )
{
	return;
}

void ClosePar::printType( void )
{
	return;
}

std::ostream & operator<<( std::ostream & stream, ClosePar const & obj )
{
	return stream << std::left << "ParClose";
}
