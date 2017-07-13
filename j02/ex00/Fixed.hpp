/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/XX/XX XX:XX:XX by student           #+#    #+#             */
/*   Updated: 2017/01/11 12:18:54 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{

private :
	int					_point;
	static int const	_number = 8;

public:

	Fixed( void );
	Fixed( Fixed const & other );
	~Fixed( void );

	int		getPoint( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	Fixed&	operator=( Fixed const & other );

};

#endif // FIXED_HPP
