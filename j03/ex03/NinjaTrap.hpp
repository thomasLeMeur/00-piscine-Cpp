/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 12:48:08 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"

class NinjaTrap : public ClapTrap
{
private:
	NinjaTrap( void );
public:

	NinjaTrap( std::string const name );
	NinjaTrap( NinjaTrap const & other );
	~NinjaTrap( void );

	NinjaTrap& operator=( NinjaTrap const & other );

	unsigned int	ninjaShoebox( std::string const & target );

};

#endif // NINJATRAP_HPP
