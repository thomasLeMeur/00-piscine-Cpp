/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sub.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/20 14:00:06 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sub.hpp"
#include <iomanip>

Sub::Sub( void ) : AToken(0, "-")
{
	return;
}

Sub::~Sub( void )
{
	return;
}

void Sub::printType( void )
{
	std::cout << std::setw(9);
	std::cout << "Substract";
}

std::ostream & operator<<( std::ostream & stream, Sub const & obj )
{
	return stream << std::left << "Op(" << obj.getName() << ")";
}
