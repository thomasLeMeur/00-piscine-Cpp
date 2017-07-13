/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:58:49 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/18 15:29:53 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <sstream>
#include "Array.hpp"

class Class
{
private:
	std::string _s;

public:
	Class( void ) : _s("String empty") {}
	Class( std::string const & s ) : _s(s) {}
	Class( Class const & other ) : _s(other._s) {}
	~Class( void ) {}

	Class& operator=( Class const & other ) { this->_s = other._s; return *this; }

	std::string const & getS( void ) const { return this->_s; }
};
std::ostream& operator<<( std::ostream & stream, Class const & obj ) { return stream << obj.getS(); }


int main( void )
{
	{
		std::cout << "Work on array of integers :" << std::endl;
		std::cout << std::endl;

		std::cout << "Create an array a" << std::endl;
		Array<int> a(12);
		for (int i = 0 ; i < 12 ; i ++)
			std::cout << "a[" << i << "] = " << a[i] << std::endl;
		std::cout << std::endl;

		std::cout << "change the values of a" << std::endl;
		for (int i = 0 ; i < 12 ; i ++)
			a[i] = i;
		for (int i = 0 ; i < 12 ; i ++)
			std::cout << "a[" << i << "] = " << a[i] << std::endl;
		std::cout << std::endl;

		std::cout << "Create an array b by copy of a" << std::endl;
		Array<int>* b = new Array<int>(a);

		std::cout << "Create an array c with the operator = on a" << std::endl;
		Array<int> c = a;

		for (int i = 0 ; i < 12 ; i ++)
			std::cout << "a[" << i << "] = " << a[i] << std::endl;
		for (int i = 0 ; i < 12 ; i ++)
			std::cout << "b[" << i << "] = " << (*b)[i] << std::endl;
		for (int i = 0 ; i < 12 ; i ++)
			std::cout << "c[" << i << "] = " << c[i] << std::endl;
		std::cout << std::endl;

		std::cout << "Change the last value of a" << std::endl;
		a[-1] = 123;
		for (int i = 0 ; i < 12 ; i ++)
			std::cout << "a[" << i << "] = " << a[i] << std::endl;
		for (int i = 0 ; i < 12 ; i ++)
			std::cout << "b[" << i << "] = " << (*b)[i] << std::endl;
		for (int i = 0 ; i < 12 ; i ++)
			std::cout << "c[" << i << "] = " << c[i] << std::endl;
		std::cout << std::endl;

		std::cout << "Try to get a value of the array with an index out of range" << std::endl;
		try
		{
			std::cout << a[12] << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "index = 12 : " << e.what() << std::endl;
		}
		try
		{
			std::cout << a[-13] << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "index = -13 : " << e.what() << std::endl;
		}
		std::cout << std::endl << std::endl;

		delete b;
	}

	{
		std::cout << "Work on array of Class :" << std::endl;
		std::cout << std::endl;

		std::cout << "Create an array a" << std::endl;
		Array<Class> a(12);
		for (int i = 0 ; i < 12 ; i ++)
			std::cout << "a[" << i << "] = " << a[i] << std::endl;
		std::cout << std::endl;

		std::cout << "change the values of a" << std::endl;
		for (int i = 0 ; i < 12 ; i ++)
		{
			std::ostringstream s;
			s << "String is " << i;
			a[i] = Class(s.str());
		}
		for (int i = 0 ; i < 12 ; i ++)
			std::cout << "a[" << i << "] = " << a[i] << std::endl;
		std::cout << std::endl;

		std::cout << "Create an array b by copy of a" << std::endl;
		Array<Class>* b = new Array<Class>(a);

		std::cout << "Create an array c with the operator = on a" << std::endl;
		Array<Class> c = a;

		for (int i = 0 ; i < 12 ; i ++)
			std::cout << "a[" << i << "] = " << a[i] << std::endl;
		for (int i = 0 ; i < 12 ; i ++)
			std::cout << "b[" << i << "] = " << (*b)[i] << std::endl;
		for (int i = 0 ; i < 12 ; i ++)
			std::cout << "c[" << i << "] = " << c[i] << std::endl;
		std::cout << std::endl;

		std::cout << "Change the last value of a" << std::endl;
		std::ostringstream s;
		s << "String is now " << 123;
		a[-1] = Class(s.str());
		for (int i = 0 ; i < 12 ; i ++)
			std::cout << "a[" << i << "] = " << a[i] << std::endl;
		for (int i = 0 ; i < 12 ; i ++)
			std::cout << "b[" << i << "] = " << (*b)[i] << std::endl;
		for (int i = 0 ; i < 12 ; i ++)
			std::cout << "c[" << i << "] = " << c[i] << std::endl;
		std::cout << std::endl;

		std::cout << "Try to get a value of the array with an index out of range" << std::endl;
		try
		{
			std::cout << a[12] << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "index = 12 : " << e.what() << std::endl;
		}
		try
		{
			std::cout << a[-13] << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "index = -13 : " << e.what() << std::endl;
		}
		std::cout << std::endl << std::endl;

		delete b;
	}

	return 0;
}
