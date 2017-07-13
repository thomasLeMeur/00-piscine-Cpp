/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:47:28 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/11 18:35:52 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdio>
#include <csignal>

void performFromFiles( int ac, char ** av)
{
	char			c;
	std::string		str;
	std::ifstream	in;

	for (int i = 1 ; i < ac ; i++)
	{
		in.open(av[i]);
		if (in.fail())
		{
			str = "cato9tails: ";
			str += av[i];
			str += ": ";
			perror(str.c_str());
		}
		else
		{
			str = "";
			while (in.get(c))
				str += c;
			std::cout << str;
		}
		in.close();
	}

	return;
}

void performFromStdin( void )
{
	while ( true )
	{
		std::string str = "";
		char		c = EOF;

		if (std::cin.eof())
			break;
		std::cin.get(c);
		while ( c != '\0' && c != '\n' && c != EOF && !std::cin.eof())
		{
			str += c;
			std::cout << c ;
			std::cin.get(c);
		}
		if (c == '\n')
		{
			std::cout << c;
			str = c;
		}

	}
	return;
}

int main( int ac, char ** av )
{
	if (ac != 1)
		performFromFiles(ac, av);
	else
		performFromStdin();
	return (0);
}
