/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecrPtr.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/19 18:42:28 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECRPTR_HPP
# define DECRPTR_HPP

#include "AMindOpen.hpp"

class DecrPtr : public AMindOpen
{
private :
	DecrPtr( void );
	DecrPtr( DecrPtr const & other );
	DecrPtr& operator=( DecrPtr const & other );

public:
	DecrPtr( std::vector<int> & tab, int & ind );
	virtual ~DecrPtr( void );

	void execute( void );

};

#endif // DECRPTR_HPP
