/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:35:48 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/12 15:34:49 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

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

	std::cout << "Time to Frag/Ninja fight :" << std::endl << std::endl;

	FragTrap d("!@#$%^");
	NinjaTrap c("UYIEQW7^");
	while ( true )
	{
		if (d.takeDamage(c.ninjaShoebox("!@#$%^")) == -1) break;
		if (c.takeDamage(d.vaulthunter_dot_exe("UYIEQW7^")) == -1) break;
	}

	std::cout << std::endl << std::endl;

	return (0);
}
