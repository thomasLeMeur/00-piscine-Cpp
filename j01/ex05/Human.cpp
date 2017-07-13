/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:58:52 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 12:31:44 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

Human::Human( void ) : _brain(120)
{
	return;
}

Human::~Human( void )
{
	return;
}

std::string Human::identify( void ) const
{
	return this->_brain.identify();
}

Brain const & Human::getBrain( void ) const
{
	return this->_brain;
}
