/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:27:04 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 17:42:16 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IPSACEMARINE_HPP
# define IPSACEMARINE_HPP

class ISpaceMarine
{
public:
		virtual ~ISpaceMarine( void ) {}

		virtual ISpaceMarine* clone( void ) const = 0;
		virtual void battleCry( void ) const = 0;
		virtual void rangedAttack( void ) const = 0;
		virtual void meleeAttack( void ) const = 0;

};

#endif // IPSACEMARINE_HPP
