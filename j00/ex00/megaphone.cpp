/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 10:42:24 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/09 11:20:39 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( int ac, char **av)
{
	int arg_cnt;

	if ( ac == 1 )
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		arg_cnt = 0;
		while ( ++arg_cnt < ac )
			while ( *av[arg_cnt] != '\0' )
			{
				if ( *av[arg_cnt] >= 'a' && *av[arg_cnt] <= 'z' )
					std::cout << (char)(*av[arg_cnt] - 'a' + 'A');
				else
					std::cout << (char)*av[arg_cnt];
				av[arg_cnt]++;
			}
		std::cout << std::endl;
	}
	return (0);
}
