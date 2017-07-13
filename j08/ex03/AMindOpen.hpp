/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMindOpen.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/19 18:44:44 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMINDOPEN_HPP
# define AMINDOPEN_HPP

#include <iostream>
#include <vector>

class AMindOpen
{
private:
	AMindOpen( void );
	AMindOpen( AMindOpen const & other );
	AMindOpen& operator=( AMindOpen const & other );

protected :
	std::vector<int> &	_tab;
	int &				_ind;

public:
	AMindOpen( std::vector<int> & tab, int & ind );
	virtual ~AMindOpen( void );

	virtual void execute( void ) = 0;

};

#endif // AMINDOPEN_HPP
