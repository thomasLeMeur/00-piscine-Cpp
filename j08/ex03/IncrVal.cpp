/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncrVal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/19 18:44:09 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IncrVal.hpp"

IncrVal::IncrVal( std::vector<int> & tab, int & ind ) : AMindOpen(tab, ind)
{
	return;
}

IncrVal::~IncrVal( void )
{
	return;
}

void IncrVal::execute( void )
{
	this->_tab[this->_ind]++;
	return;
}
