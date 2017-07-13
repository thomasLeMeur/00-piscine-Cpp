/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/XX/XX XX:XX:XX by student           #+#    #+#             */
/*   Updated: 2017/01/11 14:00:59 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{

private :
	int					_value;

public:

	static int const	_point = 8;

	Fixed( void );
	Fixed( int const n );
	Fixed( float const n );
	Fixed( Fixed const & other );
	~Fixed( void );

	int		getPoint( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	Fixed&	operator=( Fixed const & other );

};

std::ostream & operator<<( std::ostream & stream, Fixed const & var);

#endif // FIXED_HPP
