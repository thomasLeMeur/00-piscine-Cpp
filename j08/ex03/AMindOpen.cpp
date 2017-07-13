/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMindOpen.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/19 18:43:32 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMindOpen.hpp"

AMindOpen::~AMindOpen( void )
{
	return;
}

AMindOpen::AMindOpen( std::vector<int> & tab, int & ind ) : _tab(tab), _ind(ind)
{
	return;
}
