/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 13:32:28 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

class Victim
{

protected :
	std::string	_name;

	Victim( void );

public:
	Victim( std::string const name );
	Victim( Victim const & other );
	~Victim( void );

	Victim& operator=( Victim const & other );

	std::string		getName( void ) const;
	virtual void	getPolymorphed( void ) const;

};

std::ostream& operator<<( std::ostream& stream, Victim const & obj );

#endif // VICTIM_HPP
