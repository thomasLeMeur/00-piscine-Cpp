/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:35:49 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 16:42:12 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Logger.hpp"

int main( void )
{
	Logger logger("log.txt");

	logger.log("Console", "First message to console");
	logger.log("File", "First message to file");

	for (volatile int i = 0 ; i < 800000000 ; i++) ;

	logger.log("File", "Last message to file");
	logger.log("Console", "Last message to console");

	return (0);
}
