/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncrPtr.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/19 18:42:55 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCRPTR_HPP
# define INCRPTR_HPP

#include "AMindOpen.hpp"

class IncrPtr : public AMindOpen
{
private:
	IncrPtr( void );
	IncrPtr( IncrPtr const & other );
	IncrPtr& operator=( IncrPtr const & other );

public:
	IncrPtr( std::vector<int> & tab, int & ind );
	virtual ~IncrPtr( void );

	void execute( void );

};

#endif // INCRPTR_HPP
