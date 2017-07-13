/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:35:48 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/12 17:27:08 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main( void )
{
	std::cout << "Time to Frag/Scav fight :" << std::endl << std::endl;

	FragTrap a("^o-*4");
	ScavTrap b("RT-12768-hy");
	while ( true )
	{
		if (a.takeDamage(b.challengeNewcomer("^o-*4")) == -1) break;
		if (b.takeDamage(a.vaulthunter_dot_exe("RT-12768-hy")) == -1) break;
	}

	std::cout << std::endl << std::endl;

	//----------------------------

	std::cout << "Time to Super/Ninja fight :" << std::endl << std::endl;

	SuperTrap d("!@#$%^");
	NinjaTrap c("UYIEQW7^");
	int cnt = 0;
	while ( ++cnt )
	{
		if (d.takeDamage(c.ninjaShoebox("!@#$%^")) == -1) break;
		if (cnt % 2 == 1)
		{
			if (c.takeDamage(d.vaulthunter_dot_exe("UYIEQW7^")) == -1) break;
		}
		else
			if (c.takeDamage(d.ninjaShoebox("UYIEQW7^")) == -1) break;
	}

	std::cout << std::endl << std::endl;

	return (0);
}
