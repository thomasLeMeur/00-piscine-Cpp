/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncrVal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/19 18:43:02 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCRVAL_HPP
# define INCRVAL_HPP

#include "AMindOpen.hpp"

class IncrVal : public AMindOpen
{
private:
	IncrVal( void );
	IncrVal( IncrVal const & other );
	IncrVal& operator=( IncrVal const & other );

public:
	IncrVal( std::vector<int> & tab, int & ind );
	virtual ~IncrVal( void );

	void execute( void );
};

#endif // INCRVAL_HPP
