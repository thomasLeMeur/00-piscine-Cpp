/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 14:55:49 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/14 21:56:29 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Screen.hpp"
#include "Map.hpp"

int main( void )
{
	Screen scr;

	Map *map = new Map(scr.getHeight() - 5, scr.getWidth() - 5, 5, 5);
	Map *info = new Map(4, 50, 0, scr.getWidth() - 52);

	map->run(info);

	delete map;
	delete info;
	return (0);
}
