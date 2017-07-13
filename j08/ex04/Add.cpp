/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/20 14:33:31 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Add.hpp"
#include <iomanip>

Add::Add( void ) : AToken(0, "+")
{
	return;
}

Add::~Add( void )
{
	return;
}

void Add::printType( void )
{
	std::cout << std::setw(9);
	std::cout << "Add";
}

std::ostream & operator<<( std::ostream & stream, Add const & obj )
{
	return stream << "Op(" << obj.getName() << ")";
}
