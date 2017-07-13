/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 17:40:16 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{

public:

	AssaultTerminator( void );
	AssaultTerminator( AssaultTerminator const & other );
	~AssaultTerminator( void );

	AssaultTerminator& operator=( AssaultTerminator const & other );

	ISpaceMarine*	clone( void ) const;
	void			battleCry( void ) const;
	void			rangedAttack( void ) const;
	void			meleeAttack( void ) const;

};

#endif // ASSAULTTERMINATOR_HPP
