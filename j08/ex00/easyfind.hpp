/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:27:32 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/18 14:53:37 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template < typename T >
typename T::const_iterator easyfind( T const & container, int ref ) throw()
{
	return find(container.begin(), container.end(), ref);
}

#endif // EASYFIND_HPP
