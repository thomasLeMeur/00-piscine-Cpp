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
	std::cout << std::endl;

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
	std::cout << std::endl;

	//-----------------------

	Form* form;

	std::cout << "Try to create a form with a grade to sign of 0" << std::endl;
	try
	{
		form = new Form("MyForm", 0, 100);
	}
	catch(Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	//------------------------------

	std::cout << "Try to create a form with a grade to sign of 151" << std::endl;
	try
	{
		form = new Form("MyForm", 151, 100);
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	//--------------------

	std::cout << "Try to create a form with a grade to execute of 0" << std::endl;
	try
	{
		form = new Form("MyForm", 100, 0);
	}
	catch(Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	//----------------------

	std::cout << "Try to create a form with a grade to execute of 151" << std::endl;
	try
	{
		form = new Form("MyForm", 100, 151);
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	//---------------------

	form = new Form("MyForm", 100, 100);
	std::cout << *form << std::endl;

	winner = Bureaucrat("Tmp", 101);
	std::cout << winner << std::endl;
	std::cout << "Try to sign with a bureaucrat which not has the good rights" << std::endl;
	try
	{
		winner.signForm(*form);
	}
	catch (std::exception&e)
	{
		std::cout << "The form is not signed" << std::endl;
	}
	std::cout << "Actual state of the form : " << *form << std::endl;
	std::cout << std::endl;

	//-----------------------
	winner = Bureaucrat("Tmp", 100);
	std::cout << winner << std::endl;
	std::cout << "Try to sign with a bureaucrat which has the good rights" << std::endl;
	try
	{
		winner.signForm(*form);
	}
	catch (std::exception&e)
	{
		std::cout << "The form is not signed" << std::endl;
	}
	std::cout << "Actual state of the form : " << *form << std::endl;
	std::cout << std::endl;

	delete form;

	return (0);
}