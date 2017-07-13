/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetVal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/19 18:42:48 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETVAL_HPP
# define GETVAL_HPP

#include "AMindOpen.hpp"

class GetVal : public AMindOpen
{
private :
	GetVal( void );
	GetVal( GetVal const & other );
	GetVal& operator=( GetVal const & other );

public:
	GetVal( std::vector<int> & tab, int & ind );
	virtual ~GetVal( void );

	void execute( void );

};

#endif // GETVAL_HPP
