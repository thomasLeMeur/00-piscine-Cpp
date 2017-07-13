/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 19:14:23 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private :
	AMateria	**_inventory;

public:

	MateriaSource( void );
	MateriaSource( MateriaSource const & other );
	~MateriaSource( void );

	MateriaSource& operator=( MateriaSource const & other );

	void		learnMateria( AMateria* m );
	AMateria*	createMateria( std::string const & type );

};

#endif // MATERIASOURCE_HPP
