/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:22:33 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/19 14:19:10 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "span.hpp"
#include <ctime>
#include <algorithm>

int myRandom( void ) { return rand() * 2; }

int main( void )
{
	srand(time(NULL));

	{
		int n = 10;
		Span sp = Span(n);

		try
		{
			std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
		}
		catch (Span::EmptyException& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << "Longest : " << sp.longestSpan() << std::endl;
		}
		catch (Span::EmptyException& e)
		{
			std::cout << e.what() << std::endl;
		}

		for (int i = 0 ; i < n ; i++)
		{
			int val = rand() * 2;
			sp.addNumber(val);
			//std::cout << val << std::endl;
		}

		std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest : " << sp.longestSpan() << std::endl;

		try
		{
			sp.addNumber(1);
		}
		catch (Span::FullException& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "Random big creation of array" << std::endl;

		int n = 1000000;
		Span sp = Span(n);
		std::vector<int> v(n);

		std::generate(v.begin(), v.end(), myRandom);
		sp.addVector(v);

		std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest : " << sp.longestSpan() << std::endl;

		std::cout << std::endl;
	}

	return (0);
}
