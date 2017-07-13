/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 17:31:33 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{

public:

	TacticalMarine( void );
	TacticalMarine( TacticalMarine const & other );
	~TacticalMarine( void );

	TacticalMarine& operator=( TacticalMarine const & other );

	ISpaceMarine*	clone( void ) const;
	void			battleCry( void ) const;
	void			rangedAttack( void ) const;
	void			meleeAttack( void ) const;

};

#endif // TACTICALMARINE_HPP
