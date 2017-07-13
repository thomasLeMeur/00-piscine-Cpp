/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:53:34 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 13:31:01 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon
{
private :
	std::string _type;

public:
	Weapon( std::string type );
	~Weapon( void );

	std::string	const &	getType( void ) const;
	void				setType( std::string type );

};

#endif // WEAPON_HPP
