/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Div.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/20 13:59:47 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Div.hpp"
#include <iomanip>

Div::Div( ) : AToken(0, "/")
{
	return;
}

Div::~Div( void )
{
	return;
}

void Div::printType( void )
{
	std::cout << std::setw(9);
	std::cout << "Divide";
}

std::ostream & operator<<( std::ostream & stream, Div const & obj )
{
	return stream << std::left << "Op(" << obj.getName() << ")";
}
