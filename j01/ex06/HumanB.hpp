/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:53:34 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 13:30:15 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include "Weapon.hpp"

class HumanB
{
private :
	Weapon*		_weapon;
	std::string	_name;

public:
	HumanB( std::string name );
	~HumanB( void );

	void attack( void ) const;
	void setWeapon( Weapon& weapon );

};

#endif // HUMAN_B_HPP
