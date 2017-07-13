/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 19:16:45 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
private :
	std::string	_name;
	AMateria	**_inventory;

	Character( void );

public:

	Character( std::string const & name );
	Character( Character const & other );
	~Character( void );

	Character& operator=( Character const & other );

	std::string const & getName( void ) const;
	void				equip( AMateria* m );
	void				unequip( int idx );
	void				use( int idx, ICharacter& target );

};

#endif // CHARACTER_HPP
