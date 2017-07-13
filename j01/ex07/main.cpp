/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:36:07 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 15:58:57 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <regex>

int main( int ac, char **av )
{
	if (ac != 4)
		std::cout << "Usage: ./replace filename s1 s2" << std::endl;
	else if (*av[1] == '\0' || *av[2] == '\0' || *av[3] == '\0')
		std::cout << "Every argument has to be not empty" << std::endl;
	else
	{
		std::ifstream in(av[1]);

		if (in.fail())
			std::cout << "Can't open the input file " << av[1] << std::endl;
		else
		{
			std::string outname = av[1];
			outname += ".replace";
			std::ofstream out(outname);

			if (out.fail())
				std::cout << "Can't open the output file " << outname << std::endl;
			else
			{
				std::string s1(av[2]);
				std::string s2(av[3]);

				char		c;
				std::string	str = "";
				while (in.get(c))
					str += c;

				unsigned long pos = 0;
				while ((pos = str.find(s1, pos)) != std::string::npos)
				{
					str = str.replace(pos, s1.size(), s2);
					pos += s2.size();
				}
				out << str;
				out.close();
			}
			in.close();
		}
	}

	return (0);
}
