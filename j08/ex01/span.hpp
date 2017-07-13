/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/19 12:19:51 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
public:
	class FullException : public std::exception
	{
	public:
		virtual const char * what( void ) const throw()
		{
			return "The span is already filled";
		}
	};
	class EmptyException : public std::exception
	{
	public:
		virtual const char * what( void ) const throw()
		{
			return "The span has less than two numbers";
		}
	};

private:
	unsigned int		_cur;
	unsigned int		_size;
	std::vector<int>	_array;

	Span( void );

public:

	Span( unsigned int n );
	Span( Span const & other);
	~Span( void );

	void	addNumber( int value ) throw(Span::FullException);
	void	addVector( std::vector<int> const & obj ) throw(Span::FullException);

	unsigned int	shortestSpan( void ) const throw(Span::EmptyException);
	unsigned int	longestSpan( void ) const throw(Span::EmptyException);

	Span& operator=( Span const & other );

};

#endif // SPAN_HPP
