/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecrVal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/19 18:42:42 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECRVAL_HPP
# define DECRVAL_HPP

#include "AMindOpen.hpp"

class DecrVal : public AMindOpen
{
private :
	DecrVal( void );
	DecrVal( DecrVal const & other );
	DecrVal& operator=( DecrVal const & other );

public:
	DecrVal( std::vector<int> & tab, int & ind );
	virtual ~DecrVal( void );

	void execute( void );

};

#endif // DECRVAL_HPP
