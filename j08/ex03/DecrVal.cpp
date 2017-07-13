/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecrVal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/19 18:43:49 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DecrVal.hpp"

DecrVal::DecrVal( std::vector<int> & tab, int & ind ) : AMindOpen(tab, ind)
{
	return;
}

DecrVal::~DecrVal( void )
{
	return;
}

void DecrVal::execute( void )
{
	this->_tab[this->_ind]--;
	return;
}
