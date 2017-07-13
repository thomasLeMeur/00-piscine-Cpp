/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:24:55 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/16 12:32:20 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main( void )
{
	Bureaucrat* loser;

	std::cout << "Try to create a bureaucrat with level 0" << std::endl;
	try
	{
		loser = new Bureaucrat("Loser", 0);
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	//-------------------

	std::cout << "Try to create a bureaucrat with level 151" << std::endl;
	try
	{
		loser = new Bureaucrat("Loser", 151);
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	//-------------------

	loser = new Bureaucrat("Loser", 149);
	std::cout << *loser << std::endl;
	std::cout << "Try to downgrade the loser" << std::endl;
	for (int i = 0 ; i < 2 ; i++)
	{
		try
		{
			loser->downgrade();
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			std::cout << "Error during the loser action : " << e.what() << std::endl;
		}
		std::cout << *loser << std::endl;
	}

	std::cout << std::endl;

	delete loser;

	//------------------------------

	Bureaucrat winner("Winner", 2);
	std::cout << winner << std::endl;
	std::cout << "Upgrade the winner to the best level" << std::endl;
	for (int i = 0 ; i < 2 ; i++)
	{
		try
		{
			winner.upgrade();
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			std::cout << "Error during the winner action : " << e.what() << std::endl;
		}
		std::cout << winner << std::endl;
	}

	//----------------

	try
	{
		winner.upgrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Global error : " << e.what() << std::endl;
	}
	std::cout << winner << std::endl;

	return (0);
}
