/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 16:23:00 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

class Enemy
{

private :
	Enemy( void );

protected:
	int			_hp;
	std::string	_type;

public:

	Enemy( int hp, std::string const & type );
	Enemy( Enemy const & other );
	virtual ~Enemy( void );

	Enemy& operator=( Enemy const & other );

	std::string	const &	getType( void ) const;
	int					getHP( void ) const;
	virtual void		takeDamage( int amount );

};

#endif // ENEMY_HPP
