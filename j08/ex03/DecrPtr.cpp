/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecrPtr.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/19 18:43:39 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DecrPtr.hpp"

DecrPtr::DecrPtr( std::vector<int> & tab, int & ind ) : AMindOpen(tab, ind)
{
	return;
}

DecrPtr::~DecrPtr( void )
{
	return;
}

void DecrPtr::execute( void )
{
	--this->_ind;
	return;
}
