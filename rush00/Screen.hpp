/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppokar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 13:30:19 by ppokar            #+#    #+#             */
/*   Updated: 2017/01/14 13:30:21 by ppokar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <ncurses.h>

class Screen
{
public:
	Screen();
	virtual ~Screen();
	Screen(Screen const & other);
	Screen& operator=( Screen const & other );
	int getHeight() const;
	int getWidth() const;
private:
	int _height;
	int _weight;
};

#endif
