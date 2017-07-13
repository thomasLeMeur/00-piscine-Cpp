/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppokar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 13:30:09 by ppokar            #+#    #+#             */
/*   Updated: 2017/01/14 13:30:11 by ppokar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Screen.hpp"

Screen::Screen() {
	initscr();
	// clear();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	printw("Press q to exit");
	refresh();
	int h;
	int w;
	getmaxyx(stdscr, h, w);
	this->_height = h;
	this->_weight = w;
}

Screen::~Screen() {
	endwin();
}

int Screen::getHeight() const {
	return this->_height;
}

int Screen::getWidth() const {
	return this->_weight;
}

// Screen::Screen(int xpos, int ypos, int direction, char symbol ) : mapElement( xpos, ypos, direction, symbol ) {
// }

// Screen::Screen( Screen const &obj ) {
// 	*this = obj;
// }

Screen::Screen( Screen const & other )
{
	(void)other;
	return;
}

Screen& Screen::operator=( Screen const &obj ) {
 	(void)obj;
 	return *this;
 }
