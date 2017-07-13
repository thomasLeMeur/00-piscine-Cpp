/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AToken.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/20 13:03:30 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AToken.hpp"

AToken::AToken( int val, std::string const & name ) : _val(val), _name(name)
{
	return;
}

AToken::~AToken( void )
{
	return;
}

int AToken::getVal( void ) const
{
	return this->_val;
}

std::string AToken::getName( void ) const
{
	return this->_name;
}
