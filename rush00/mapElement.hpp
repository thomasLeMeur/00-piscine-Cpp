/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapElement.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppokar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 10:43:32 by ppokar            #+#    #+#             */
/*   Updated: 2017/01/14 21:40:57 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPELEMENT_HPP
#define MAPELEMENT_HPP

class mapElement
{
public:
	mapElement();
	virtual ~mapElement();
	mapElement( double xpos, double ypos, double direction, char symbol );
	mapElement( mapElement const &obj );
	mapElement& operator=( mapElement const &obj );
	double getXpos( void ) const;
	double getYpos( void ) const;
	void setXpos( double xpos );
	void setYpos( double xpos );
	virtual void printForm()=0;
	double getDirection() const;
	void setDirection( double direction );
	char getSymbol( void ) const;

protected:
	double _xpos;
	double _ypos;
	double _dir;
	char _symbol;
};

#endif
