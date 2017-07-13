/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 19:04:06 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"
class ICharacter;

class AMateria
{
private :
	std::string		_type;
	unsigned int	_xp;

	AMateria( void );

public:

	AMateria( std::string const & type);
	AMateria( AMateria const & other );
	virtual ~AMateria( void );

	AMateria& operator=( AMateria const & other );

	std::string const & getType( void ) const;
	unsigned int		getXP( void ) const;

	virtual AMateria*	clone( void ) const = 0;
	virtual void		use( ICharacter& target );

	void				setType( std::string const & type );
	void				setXP( unsigned int xp );

};

#endif // AMATERIA_HPP
