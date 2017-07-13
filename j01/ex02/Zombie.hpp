/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:53:34 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 11:31:42 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie
{

private :
	std::string const	_type;
	std::string	const	_name;

public:
	Zombie( std::string const type, std::string const name );
	~Zombie( void );

	void announce( void ) const ;

};

#endif // ZOMBIE_HPP
