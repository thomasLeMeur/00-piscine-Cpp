/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:07:02 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/17 14:17:59 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Base { public : virtual ~Base( void ) {}; };

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate( void )
{
	int val = rand() % 3;
	if (val == 0)
	{
		//std::cout << "A created" << std::endl;
		return new A();
	}
	else if (val == 1)
	{
		//std::cout << "B created" << std::endl;
		return new B();
	}
	else
	{
		//std::cout << "C created" << std::endl;
		return new C();
	}
}

void identify_from_pointer( Base * p )
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
	return;
}

void identify_from_reference( Base & p )
{
	try
	{
		A tmp = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::bad_cast& a)
	{
		try
		{
			B tmp = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
			return;
		}
		catch (std::bad_cast& b)
		{
			try
			{
				C tmp = dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
				return;
			}
			catch (std::bad_cast& c)
			{
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
	return;
}

int main( void )
{
	srand(time(NULL));

	for (int i = 0 ; i < 5 ; i ++)
	{
		Base *elem = generate();

		std::cout << "From pointer : ";
		identify_from_pointer(elem);

		std::cout << "From reference : ";
		identify_from_reference(*elem);

		std::cout << std::endl;

		delete elem;
	}

	return 0;
}
