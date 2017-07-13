/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:53:34 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 10:17:29 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

class Pony
{
private :
	int _nbOfLegs;
	int _weight;
	int _size;

public:
	Pony( int const nbOfLegs, int const weight, int const size );
	~Pony( void );

	void ponyOnTheHeap( int const nbOfLegs, int const weight, int const size );
	void ponyOnTheStack( int const nbOfLegs, int const weight, int const size );

};

#endif // PONY_HPP
