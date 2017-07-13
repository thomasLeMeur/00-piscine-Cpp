/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/XX/XX XX:XX:XX by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy( void )
{
	srand(time(NULL));
	this->_queue = "";
	this->_nbWorkers = 0;
	return;
}

CentralBureaucracy::CentralBureaucracy( CentralBureaucracy const & other )
{
	srand(time(NULL));
	(void)other;
	return;
}

CentralBureaucracy::~CentralBureaucracy( void )
{
	return;
}

CentralBureaucracy& CentralBureaucracy::operator=( CentralBureaucracy const & other )
{
	srand(time(NULL));
	(void)other;
	return *this;
}

void CentralBureaucracy::feed( Bureaucrat & man )
{
	if (this->_nbWorkers < 20)
	{
		if (this->_nbWorkers % 2 == 0)
		{
			Intern intern;
			this->_blocks[this->_nbWorkers / 2].setIntern(intern);
			this->_blocks[this->_nbWorkers / 2].setSigner(man);
		}
		else
			this->_blocks[this->_nbWorkers / 2].setExecutor(man);
		this->_nbWorkers++;
	}
	else
		std::cout << "The center is full" << std::endl;
	return;
}

void CentralBureaucracy::queueUp( std::string const & target )
{
	this->_queue += target;
	this->_queue += " ";
	return;
}

void CentralBureaucracy::doBureaucracy( void )
{
	std::string forms[4] = { "ShrubberyCreation", "RobotomyRequest", "PresidentialPardon", "UnknownForm" };
	
	for (int i = 0 ; this->_queue != "" ; i = (i + 1) % (this->_nbWorkers / 2))
	{
		//std::cout << this->_queue << std::endl;
		int pos = this->_queue.find(" ");
		std::string target = this->_queue.substr(0, pos);
		this->_queue = this->_queue.substr(pos + 1, this->_queue.size() - pos - 1);
		//std::cout << this->_queue << std::endl;

		try
		{
			this->_blocks[i].doBureaucracy(forms[rand() % 4], target);
		}
		catch (OfficeBlock::MissingEmployeeException& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "An error occured : " << e.what() << std::endl;
		}
		
		std::cout << std::endl;
	}
	return;
}