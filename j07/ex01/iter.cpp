/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:53:44 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/18 15:47:55 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Class
{
private:
	int _val;

public:
	Class( void ) {};
	Class( int val ) : _val(val) {};
	int getVal( void ) const { return this->_val; }
};
std::ostream& operator<<( std::ostream & stream, Class const & obj ) { return stream << obj.getVal(); }

template < typename T > void print1( T const & obj ) { std::cout << obj << std::endl; }
void print2( int const & obj ) { std::cout << obj << std::endl; }


template < typename T >
void iter( T const * tab, unsigned int const len, void (*f)( T const & arg ))
{
	for ( unsigned int i = 0 ; i < len ; i++ )
		(*f)(tab[i]);
}

int main( void )
{
	{
		int a[4] = {1, 4, 34, -56 };
		iter(a, 4, print2);
		std::cout << std::endl;
	}

	//-------------------
	{
		double a[4] = {1.5, 4.8, 34.2, -56.8 };
		iter(a, 4, print1);
		std::cout << std::endl;
	}

	//-------------------

	{
		Class a[5] = { Class(5), Class(-2), Class(45), Class(23), Class(45) };
		iter(a, 5, print1);
		std::cout << std::endl;
	}

	return 0;
}
