/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:44:25 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 16:34:42 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <fstream>

class Logger
{

private:
	std::ofstream*	_file;
	std::string		_arrayOfNames[2];
	void ( Logger::*_arrayOfFunctions[2])( std::string const & message) const;

	void				logToConsole( std::string const & message ) const;
	void				logToFile( std::string const & message ) const;
	std::string const	makeLogEntry( std::string message) const;

public:
	Logger( std::string filename );
	~Logger( void );

	void log( std::string const & dest, std::string const & message );

};

#endif // LOGGER_HPP
