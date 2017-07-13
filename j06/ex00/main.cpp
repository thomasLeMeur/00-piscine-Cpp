/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:15:02 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/17 15:03:15 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

void printChar( char c )
{
	if ((c < 32 || c == 127) && (c != 9))
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	return;
}

void printExcept( std::string s)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(atof(s.c_str())) << "f" << std::endl;
	std::cout << "double: " << atof(s.c_str()) << std::endl;
	return;
}

void printFloat( std::string s )
{
	double val1 = atof(s.c_str());
	int val2 = static_cast<int>(val1);

	if ((val2 < 32 || val2 == 127) && (val2 != 9))
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(val2) << "'" << std::endl;
	std::cout << "int: " << val2 << std::endl;

	if (val1 != val2)
	{
		std::cout << "float: " << static_cast<float>(val1) << "f" << std::endl;
		std::cout << "double: " << val1 << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(val1) << ".0f" << std::endl;
		std::cout << "double: " << val1 << ".0" << std::endl;
	}
	return;
}

int main( int ac, char ** av )
{
	if (ac != 2)
	{
		std::cout << "Usage: ./prog value" << std::endl;
		return 0;
	}

	std::string val(av[1]);
	if (val.size() == 1 && (val[0] < '0' || val[0] > '9'))
		printChar(val[0]);
	else
	{
		while (val[0] == ' ' || val[0] == '\t')
			val = val.substr(1, val.size() - 1);
		while (val[val.size() - 1] == ' ' || val[val.size() - 1] == '\t')
			val = val.substr(0, val.size() - 1);
		if (val.size() == 0)
		{
			std::cout << "Wrong parameter" << std::endl;
			return (0);
		}
		else if (val == "-inff" || val == "+inff" || val == "nanf" || val == "-inf" || val == "+inf" || val == "nan")
			printExcept(val);
		else
		{
			int i = 0;
			if (val[i] == '-' || val[i] == '+')
				i++;
			int nbDots = 0, nbF = 0, nbD = 0;
			for ( ; i < val.size() ; i ++)
			{
				if (val[i] == '.') nbDots++;
				if (val[i] == 'f') nbF++;
				if (val[i] >= '0' && val[i] <= '9') nbD++;
				if (nbDots > 1 || nbF > 1 || ((val[i] < '0' || val[i] > '9') && val[i] != '.' && val[i] != 'f'))
				{
					std::cout << "Wrong parameter" << std::endl;
					return (0);
				}
				else if ((val[i] == 'f' && i != val.size() - 1))
				{
					std::cout << "Wrong parameter" << std::endl;
					return (0);
				}
			}
			if (!nbD)
			{
				std::cout << "Wrong parameter" << std::endl;
				return (0);
			}
			printFloat(val);
		}
	}

	return 0;
}
