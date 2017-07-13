/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncrPtr.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/19 18:44:03 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IncrPtr.hpp"

IncrPtr::IncrPtr( std::vector<int> & tab, int & ind ) : AMindOpen(tab, ind)
{
	return;
}

IncrPtr::~IncrPtr( void )
{
	return;
}

void IncrPtr::execute( void )
{
	++this->_ind;
	return;
}
