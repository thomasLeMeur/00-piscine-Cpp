/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:58:52 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 12:38:10 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Brain.hpp"

Brain::Brain( int const weight) : _weight(weight)
{
	(void)this->_weight; // keep membre attributes but just display two adress
	return;
}

Brain::~Brain( void )
{
	return;
}

std::string Brain::identify( void ) const
{
	std::stringstream sstr;

	sstr << this;

	std::string str(sstr.str());
	std::string last = "";

	for (unsigned int i = 0 ; i < str.size() ; i++)
		if (str[i] >= 'a' && str[i] <= 'z')
			last += (char)(str[i] - 'a' + 'A');
		else
			last += str[i];
	return last;
}
