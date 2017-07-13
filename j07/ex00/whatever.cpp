/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:53:44 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/19 17:32:53 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Class
{
private:
	int _val;

public:
	Class( int val ) : _val(val) {};
	bool operator<( Class const & other ) { return (this->_val < other._val); }
	bool operator>( Class const & other ) { return (this->_val > other._val); }
	bool operator<=( Class const & other ) { return (this->_val <= other._val); }
	bool operator>=( Class const & other ) { return (this->_val >= other._val); }
	bool operator==( Class const & other ) { return (this->_val == other._val); }
	bool operator!=( Class const & other ) { return (this->_val != other._val); }

	int getVal( void ) const { return this->_val; }
};
std::ostream& operator<<( std::ostream & stream, Class const & obj ) { return stream << obj.getVal(); }


template < typename T > T const & min( T & a, T & b ) { return (a <= b ? a : b ); }
template < typename T > T const & max( T & a, T & b ) { return (a >= b ? a : b ); }
template < typename T > void swap( T & a, T & b ) { T c = a; a = b; b = c; }

int main( void )
{
	{
		int a = 12;
		int b = 23;
		std::cout << "The max of the two int " << a << " and "<< b << " is " << ::max(a, b) << std::endl;
		std::cout << "The min of the two int " << a << " and "<< b << " is " << ::min(a, b) << std::endl;
		::swap(a, b);
		std::cout << "After the swap, the values are " << a << " and " << b << std::endl;
		std::cout << std::endl;
	}

	//-------------------

	{
		float a = 12;
		float b = 23;
		std::cout << "The max of the two float " << a << " and "<< b << " is " << ::max(a, b) << std::endl;
		std::cout << "The min of the two float " << a << " and "<< b << " is " << ::min(a, b) << std::endl;
		::swap(a, b);
		std::cout << "After the swap, the values are " << a << " and " << b << std::endl;
		std::cout << std::endl;
	}

	//-------------------

	{
		std::string a("12");
		std::string b("23");
		std::cout << "The max of the two strings " << a << " and "<< b << " is " << ::max(a, b) << std::endl;
		std::cout << "The min of the two strings " << a << " and "<< b << " is " << ::min(a, b) << std::endl;
		::swap(a, b);
		std::cout << "After the swap, the values are " << a << " and " << b << std::endl;
		std::cout << std::endl;
	}

	//-------------------

	{
		Class a(12);
		Class b(23);
		std::cout << "The max of the two class " << a << " and "<< b << " is " << ::max(a, b) << std::endl;
		std::cout << "The min of the two class " << a << " and "<< b << " is " << ::min(a, b) << std::endl;
		::swap(a, b);
		std::cout << "After the swap, the values are " << a << " and " << b << std::endl;
		std::cout << std::endl;
	}

	return 0;
}
