/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/18 15:29:07 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

#ifndef ARRAY_HPP
#define ARRAY_HPP

template < typename T >
class Array
{
public:
	class OutOfRangeException : public std::exception
	{
	public:
		virtual const char * what( void ) const throw()
		{
			return "The index is out of range";
		}
	};

private:
	unsigned int	_size;
	T *				_array;

public:

	Array<T>( void ) : _size(0), _array(new T[0]())
	{
		return;
	}

	Array<T>( unsigned int n ) : _size(n), _array(new T[n]())
	{
		return;
	}

	Array<T>( Array<T> const & other ) : _size(other._size), _array(new T[other._size])
	{
		for (unsigned int i = 0 ; i < other._size ; i++)
			this->_array[i] = other._array[i];
		return;
	}

	virtual ~Array<T>( void )
	{
		delete [] this->_array;
		return;
	}

	Array<T>& operator=( Array<T> const & other )
	{
		delete [] this->_array;

		this->_size = other._size;
		this->_array = new T[other._size];
		for (unsigned int i = 0 ; i < other._size ; i++)
			this->_array[i] = other._array[i];
		return *this;
	}

	unsigned int size( void ) const
	{
		return this->_size;
	}

	T& operator[]( int ind ) throw( std::exception )
	{
		if (ind >= (int)this->_size || -ind > (int)this->_size )
			throw Array<T>::OutOfRangeException();
		else if (ind >= 0)
			return this->_array[ind];
		else
			return this->_array[this->_size + ind];
	}

	T const & operator[]( int ind ) const throw( std::exception )
	{
		if (ind >= (int)this->_size || -ind > (int)this->_size )
			throw Array<T>::OutOfRangeException();
		else if (ind >= 0)
			return this->_array[ind];
		else
			return this->_array[this->_size + ind];
	}

};

#endif // ARRAY_HPP
