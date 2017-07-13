/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/19 12:20:05 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include "span.hpp"
#include <iostream>
Span::Span( void ) : _cur(0), _size(0), _array()
{
	return;
}

Span::Span( unsigned int n ) : _cur(0), _size(n), _array(n, 0)
{
	return;
}

Span::Span( Span const & other ) : _cur(other._cur), _size(other._size), _array(other._array)
{
	return;
}

Span::~Span( void )
{
	return;
}

void Span::addNumber( int value ) throw(Span::FullException)
{
	if (this->_cur == this->_size)
		throw Span::FullException();
	else
		this->_array[this->_cur++] = value;
	return;
}

void Span::addVector( std::vector<int> const & obj ) throw(Span::FullException)
{
	if (this->_cur == this->_size)
		throw Span::FullException();
	else
	{
		this->_array.insert(this->_array.begin() + this->_cur, obj.begin(), this->_cur + obj.size() > this->_size ? obj.end() - (this->_size - this->_cur): obj.end());
		this->_cur = this->_cur + obj.size() > this->_size ? this->_size : this->_cur + obj.size();
	}
	return;
}

unsigned int Span::shortestSpan( void ) const throw(Span::EmptyException)
{
	if (this->_cur <= 1)
		throw Span::EmptyException();
	else
	{
		std::vector<int> tmp(this->_array);
		std::sort(tmp.begin(), tmp.begin() + this->_cur);
		unsigned int d = UINT_MAX;
		for (unsigned int i = 0 ; i < this->_cur - 1 ; i++)
			d = std::min(d, static_cast<unsigned int>(std::abs(static_cast<long>(tmp[i]) - tmp[i + 1])));
		return d;
	}
}

unsigned int Span::longestSpan( void ) const throw(Span::EmptyException)
{
	if (this->_cur <= 1)
		throw Span::EmptyException();
	else
	{
//		std::vector<int> tmp(this->_array);
//		std::sort(tmp.begin(), tmp.begin() + this->_cur);
		return *std::max_element(this->_array.begin(), this->_array.end()) - *std::min_element(this->_array.begin(), this->_array.end());
//		return tmp[tmp.size() - 1] - tmp[0];
	}
}

Span& Span::operator=( Span const & other )
{
	this->_array = other._array;
	this->_cur = other._cur;
	this->_size = other._size;
	return *this;
}
