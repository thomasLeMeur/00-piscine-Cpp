/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Num.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/20 13:59:54 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Num.hpp"
#include <iomanip>

Num::Num( int val ) : AToken(val, "")
{
	return;
}

Num::~Num( void )
{
	return;
}

void Num::printType( void )
{
	std::cout << std::setw(9);
	std::cout << "Push";
}

std::ostream & operator<<( std::ostream & stream, Num const & obj )
{
	return stream << std::left << "Num(" << obj.getVal() << ")";
}
