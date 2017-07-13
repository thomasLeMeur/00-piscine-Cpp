/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:49:50 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 16:44:09 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Logger.hpp"

Logger::Logger( std::string filename )
{
	this->_file = new std::ofstream(filename, std::ios::app);
	this->_arrayOfNames[0] = "Console";
	this->_arrayOfNames[1] = "File";
	this->_arrayOfFunctions[0] = &Logger::logToConsole;
	this->_arrayOfFunctions[1] = &Logger::logToFile;
	return;
}

Logger::~Logger( void )
{
	this->_file->close();
	delete this->_file;
	return;
}

void Logger::log( std::string const & dest, std::string const & message)
{
	for (int i = 0 ; i < 2 ; i++)
		if (this->_arrayOfNames[i] == dest)
			(this->*_arrayOfFunctions[i])(this->makeLogEntry(message));
	return;
}

void Logger::logToConsole( std::string const & message ) const
{
	std::cout << message << std::endl;
	return;
}

void Logger::logToFile( std::string const & message ) const
{
	*this->_file << message << std::endl;
	return;
}

std::string const Logger::makeLogEntry( std::string message ) const
{
	time_t		rawtime;
	struct tm	*timeinfo;
	char		buffer[128];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 127, "[%Y%m%d_%H%M%S] <", timeinfo);

	std::string str(buffer);
	str += message + ">";
	return str;
}
