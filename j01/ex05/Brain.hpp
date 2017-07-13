/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:53:34 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 12:30:54 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

class Brain
{
private :
	int const	_weight;

public:
	Brain( int const weight );
	~Brain( void );

	std::string identify( void ) const;

};

#endif // BRAIN_HPP
