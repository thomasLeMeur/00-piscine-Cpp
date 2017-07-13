/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PutVal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/19 18:45:18 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PutVal.hpp"

PutVal::PutVal( std::vector<int> & tab, int & ind ) : AMindOpen(tab, ind)
{
	return;
}

PutVal::~PutVal( void )
{
	return;
}

void PutVal::execute( void )
{
	std::cout << static_cast<char>(this->_tab[this->_ind]);
	return;
}
