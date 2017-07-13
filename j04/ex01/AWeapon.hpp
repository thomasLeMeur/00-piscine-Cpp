/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 16:23:13 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

class AWeapon
{

protected :
	std::string		_name;
	unsigned int	_apcost;
	unsigned int	_damage;

private:
	AWeapon( void );

public:

	AWeapon( std::string const & name, int apcost, int damage);
	AWeapon( AWeapon const & other );
	virtual ~AWeapon( void );

	AWeapon& operator=( AWeapon const & other );

	std::string		getName( void ) const;
	int				getAPCost( void ) const;
	int				getDamage( void ) const;

	virtual void	attack( void ) const = 0;
};

#endif // AWEAPON_HPP
