/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AToken.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/20 13:03:12 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOKEN_HPP
# define ATOKEN_HPP

#include <iostream>

class AToken
{
private :
	AToken( void );
	AToken( AToken const & other );
	AToken& operator=( AToken const & other );

protected:
	int			_val;
	std::string	_name;

public:
	AToken( int val, std::string const & name );
	virtual ~AToken( void );

	virtual void	printType( void ) = 0;
	int				getVal( void ) const;
	std::string		getName( void ) const;
};

#endif // ATOKEN_HPP
