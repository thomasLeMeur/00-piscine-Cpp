/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 16:21:43 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{

private :
	std::string _name;
	int			_nbap;
	AWeapon*	_weapon;

	Character( void );

public:

	Character( std::string const & name );
	Character( Character const & other );
	~Character( void );

	Character& operator=( Character const & other );

	void			recoverAP( void );
	void			equip( AWeapon* weapon );
	void			attack( Enemy* enemy );

	std::string const &	getName( void ) const;
	AWeapon const *		getWeapon( void ) const;
	int					getNbAP( void ) const;

};

std::ostream& operator<<( std::ostream&stream, Character const & obj );

#endif // CHARACTER_HPP
