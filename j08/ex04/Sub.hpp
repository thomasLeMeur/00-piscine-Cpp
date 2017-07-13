/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sub.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/20 12:01:45 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUB_HPP
# define SUB_HPP

#include "AToken.hpp"

class Sub : public AToken
{
private :
	Sub( Sub const & other );
	Sub& operator=( Sub const & other );

public:
	Sub( void );
	virtual ~Sub( void );

	void printType( void );

};
std::ostream & operator<<( std::ostream & stream, Sub const & obj );

#endif // SUB_HPP
