/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/XX/XX XX:XX:XX by student           #+#    #+#             */
/*   Updated: 2017/01/19 11:23:32 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <stack>
#include <deque>

template < typename T, typename U = std::deque<T> >
class MutantStack : public std::stack<T, U>
{
public :
	typedef typename U::iterator		iterator;
	typedef typename U::const_iterator	const_iterator;

public:
	MutantStack< T, U >( void ) : std::stack<T, U>() {}
	MutantStack< T, U >( MutantStack< T, U > const & other ) : std::stack< T, U >(other) {}
	~MutantStack< T, U >( void ) {}

	MutantStack< T, U >& operator=( MutantStack< T, U > const & other ) { static_cast<std::stack< T, U > &>(*this) = static_cast<std::stack< T, U > &>(other); }

	iterator	begin( void ) { return this->c.begin(); }
	iterator	end( void ) { return this->c.end(); }

};

#endif
