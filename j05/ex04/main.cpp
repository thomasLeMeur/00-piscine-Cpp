/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:24:55 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/16 16:04:28 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include <iostream>

int main( void )
{
	Intern idiotOne;
	Bureaucrat *hermes;
	Bureaucrat *bob;
	OfficeBlock ob;
	
	//--------------------------------

	std::cout << "Create a new office with missing employees and try to do bureaucrary" << std::endl;

	OfficeBlock* tmp = new OfficeBlock(0, 0, 0);

	try
	{
		tmp->doBureaucracy("PresidentialPardon", "ERROR");
	}
	catch (OfficeBlock::MissingEmployeeException& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	delete tmp;

	//------------------------------------

	std::cout << "Use an intern and two sudo to sign and execute" << std::endl;

	hermes = new Bureaucrat("Hermes", 1);
	bob = new Bureaucrat("Bob", 1);

	ob.setIntern(idiotOne);
	ob.setSigner(*bob);
	ob.setExecutor(*hermes);

	try
	{
		ob.doBureaucracy("RobotomyRequest", "Target1");
	}
	catch (std::exception& e)
	{
		std::cout << "An error occured" << std::endl;
	}

	std::cout << std::endl;

	delete bob;
	delete hermes;

	//-----------------------

	std::cout << "Creation of a signer which has no the good rights" << std::endl;

	hermes = new Bureaucrat("Hermes", 1);
	bob = new Bureaucrat("Bob", 150);

	ob.setSigner(*bob);
	ob.setExecutor(*hermes);

	try
	{
		ob.doBureaucracy("RobotomyRequest", "Target2");
	}
	catch (std::exception& e)
	{
		std::cout << "An error occured" << std::endl;
	}

	std::cout << std::endl;

	delete bob;
	delete hermes;

	//------------------------------------

	std::cout << "Creation of an executor which has no the good rights" << std::endl;

	hermes = new Bureaucrat("Hermes", 150);
	bob = new Bureaucrat("Bob", 1);

	ob.setSigner(*bob);
	ob.setExecutor(*hermes);

	try
	{
		ob.doBureaucracy("RobotomyRequest", "Target3");
	}
	catch (std::exception& e)
	{
		std::cout << "An error occured" << std::endl;
	}

	std::cout << std::endl;

	delete bob;
	delete hermes;

	//------------------------------------

	std::cout << "Creation of a wrong form" << std::endl;

	hermes = new Bureaucrat("Hermes", 1);
	bob = new Bureaucrat("Bob", 1);

	ob.setSigner(*bob);
	ob.setExecutor(*hermes);

	try
	{
		ob.doBureaucracy("WrongForm", "Target4");
	}
	catch (std::exception& e)
	{
		std::cout << "An error occured" << std::endl;
	}

	std::cout << std::endl;

	delete bob;
	delete hermes;

	return (0);
}
