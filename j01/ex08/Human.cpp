/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:54:49 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 15:27:12 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

void Human::meleeAttack( std::string const & target )
{
	std::cout << "During the melee attack, the target is '" << target << "'" << std::endl;
	return;
}

void Human::rangedAttack( std::string const & target )
{
	std::cout << "During the ranged attack, the target is '" << target << "'" << std::endl;
	return;
}

void Human::intimidatingShout( std::string const & target )
{
	std::cout << "During the intimidating shout, the target is '" << target << "'" << std::endl;
	return;
}

void Human::action( std::string const & action_name, std::string const & target )
{
	std::string arrayOfNames[3] = {"Melee Attack", "Ranged Attack", "Intimidating Shout"};
	void ( Human::*arrayOfFunctions[3] )( std::string const & target ) = { &Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};

	for (int i = 0 ; i < 3 ; i++)
		if ( action_name == arrayOfNames[i] )
			(this->*arrayOfFunctions[i])(target);
	return;
}
