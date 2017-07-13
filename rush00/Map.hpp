/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/15 10:12:51 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <ctime>
#include "Squad.hpp"
#include "PlayerShip.hpp"
#include <ncurses.h>
#include "Screen.hpp"

class Map
{
private :
	int			_row;
	int			_col;
	int			_width;
	int			_height;
	int			_nbCases;
	Squad		_enemies;
	PlayerShip	_player;
	int			_score;
	clock_t		_prev;
	clock_t		_cur;
	char		_timeStr[32];
	WINDOW*		_w;
	int			_nbTurns;

	Map( void );
	Map( Map const & other );
	Map& operator=( Map const & other );

	char*	getPrintableTime( void );
	void	updatePlayerStuff( void );
	void	updateEnemiesStuff( void );
	void	infosPrint( Map * info );
	void	createNextTurnOfEnemies( void );
	void	getUserAction( int ch );

public:

	static double	timeBeforeUpdate; //frame = 60Hz

	Map(int nr_rows, int nr_cols, int row_O, int col_O);
	virtual ~Map( void );

	void run( Map * info );

	WINDOW *getWindow();
	WINDOW *frameResize(Screen const &obj);
	void show(mapElement &x);
	void show(mapElement &x, double col_0, double row_0);
	void erase(mapElement &x);
	void refresh();
	void showMsg(int xpos, int ypos, const char *msg);

};

#endif // MAP_HPP
