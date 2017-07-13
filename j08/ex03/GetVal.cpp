/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetVal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/19 18:43:56 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GetVal.hpp"
#include <cstdio>

GetVal::GetVal( std::vector<int> & tab, int & ind ) : AMindOpen(tab, ind)
{
	return;
}

GetVal::~GetVal( void )
{
	return;
}

void GetVal::execute( void )
{
	this->_tab[this->_ind] = getchar();
	return;
}
