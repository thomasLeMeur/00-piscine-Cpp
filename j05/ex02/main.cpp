/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:24:55 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/16 10:24:56 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main( void )
{

	std::cout << "Creation of the 3 forms and a sudo" << std::endl;

	RobotomyRequestForm*   form1 = new RobotomyRequestForm("Target1");
	ShrubberyCreationForm  form2("Target2");
	PresidentialPardonForm form3("Target3");
	Bureaucrat sudo("Sudo", 1);
	
	std::cout << sudo << std::endl;
	std::cout << *form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;

	std::cout << std::endl;


	//------------------------------------

	std::cout << "Try to execute with sudo a form unsigned" << std::endl;
	
	sudo.executeForm(*form1);
	
	std::cout << std::endl;

	//-----------------------------------
	
	std::cout << "Sign the 3 forms with sudo" << std::endl;
	
	sudo.signForm(*form1);
	sudo.signForm(form2);
	sudo.signForm(form3);

	std::cout << *form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;

	std::cout << std::endl;

	//----------------------------------

	std::cout << "Create a man with no rights and try to execute the 3 forms" << std::endl;

	Bureaucrat *victim = new Bureaucrat("Victim", 150);
	
	std::cout << *victim << std::endl;

	victim->executeForm(*form1);
	victim->executeForm(form2);
	victim->executeForm(form3);
	
	std::cout << std::endl;

	//---------------------------------

	std::cout << "Execute the 3 forms with sudo" << std::endl;

	sudo.executeForm(*form1);
	sudo.executeForm(form2);
	sudo.executeForm(form3);

	std::cout << std::endl;

	//-------------------------------

	delete form1;
	delete victim;

	return (0);
}