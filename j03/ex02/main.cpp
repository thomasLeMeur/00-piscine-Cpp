/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:35:48 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/12 14:37:33 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	FragTrap a("^o-*4");
	ScavTrap b("RT-12768-hy");
	while ( true )
	{
		if (a.takeDamage(b.challengeNewcomer("^o-*4")) == -1) break;
		if (b.takeDamage(a.vaulthunter_dot_exe("RT-12768-hy")) == -1) break;
	}
	return (0);
}
