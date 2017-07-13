/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mul.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/20 13:59:51 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mul.hpp"
#include <iomanip>

Mul::Mul( void ) : AToken(0, "*")
{
	return;
}

Mul::~Mul( void )
{
	return;
}

void Mul::printType( void )
{
	std::cout << std::setw(9);
	std::cout << "Multiply";
}

std::ostream & operator<<( std::ostream & stream, Mul const & obj )
{
	return stream << std::left << "Op(" << obj.getName() << ")";
}
