/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:24:57 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 15:26:48 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

int main( void )
{
	Human it;

	it.action("Melee Attack", "first one");
	it.action("Ranged Attack", "second one");
	it.action("Intimidating Shout", "third one");
	it.action("Test", "fourth one");

	return (0);
}
