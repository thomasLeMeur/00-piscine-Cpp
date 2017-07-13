/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 12:10:52 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 12:13:03 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void )
{
	std::string str = "HI THIS IS BRAIN";

	std::string* ptr = &str;
	std::string& ref = str;

	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;

	return (0);
}
