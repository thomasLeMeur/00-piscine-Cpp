/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PutVal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/19 18:43:09 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUTVAL_HPP
# define PUTVAL_HPP

#include "AMindOpen.hpp"

class PutVal : public AMindOpen
{
private :
	PutVal( void );
	PutVal( PutVal const & other );
	PutVal& operator=( PutVal const & other );

public:
	PutVal( std::vector<int> & tab, int & ind );
	virtual ~PutVal( void );

	void execute( void );

};

#endif // PUTVAL_HPP
