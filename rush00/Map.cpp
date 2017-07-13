/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/17 16:33:21 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdio>
#include <ctime>
#include "Map.hpp"
#include "EnemyShip.hpp"
#include "Asteroid.hpp"
#include <sstream>

double Map::timeBeforeUpdate = CLOCKS_PER_SEC / 9.0f;

Map::Map( void )
{
	return;
}

Map::Map( Map const & other )
{
	(void)other;
	return;
}

Map& Map::operator=( Map const & other )
{
	(void)other;
	return *this;
}

void Map::createNextTurnOfEnemies( void )
{
	int nbOfEnemies = rand() % int((2 * (this->_width - 12.) / 100. + 1));
	for (int i = 0 ; i < nbOfEnemies ; i++)
	{
		ASpaceShip* enemy;
		if (rand() % 101 < 20)
			enemy = new Asteroid();
		else
			enemy = new EnemyShip();
		enemy->setDirection(1.);
		enemy->setYpos(1);

		int xpos = 0;
		int proof = true;
		while (proof)
		{
			proof = false;
			xpos = rand() % (this->_width - 12) + 5;
			for (int j = 0 ; j < this->_enemies.getCount() ; j++)
			{
				if (this->_enemies.getUnit(j) != 0 && (int)this->_enemies.getUnit(j)->getYpos() == 0 && (int)this->_enemies.getUnit(j)->getXpos() == xpos)
				{
					proof = true;
					break;
				}
			}
			if ((int)this->_player.getYpos() == 1 && (int)this->_player.getXpos() == xpos)
				proof = true;
		}
		enemy->setXpos(xpos);
		this->_enemies.push(enemy);
		this->show(*enemy);
	}

	if (this->_nbTurns % 3 == 0)
	{
		for (int i = 1 ; i <= 5 ; i++)
		{
			if (rand() % 101 <= 100 / i)
			{
				EnemyShip* enemy = new EnemyShip(i, 1, 1. / 3., (unsigned int)-1, '>');
				this->_enemies.push(enemy);
				show(*enemy);
			}
		}

		for (int i = 1 ; i < 5 ; i++)
		{
			if (rand() % 101 <= 100 / i)
			{
				EnemyShip* enemy = new EnemyShip(this->_width - i - 1, 1, 1. / 3., (unsigned int)-1, '>');
				this->_enemies.push(enemy);
				show(*enemy);
			}
		}
	}

	for (int i = 0 ; i < this->_enemies.getCount() ; i++)
	{
		ASpaceShip* tmpShip = this->_enemies.getUnit(i);
		if (tmpShip != 0 && tmpShip->getHP() > 0 && tmpShip->getYpos() < this->_height - 2 && (int)tmpShip->getWeapon().getDamage() > 0 && (int)tmpShip->getYpos() > 0 && rand() % 1000 < 30)
		{
			tmpShip->getWeapon().createShoot(tmpShip->getXpos(), tmpShip->getYpos() - 1, tmpShip->getDirection() + 1. / 3., tmpShip->getWeapon().getSymbol());
			show(*tmpShip->getWeapon().getShoot(tmpShip->getWeapon().getNbShoots() - 1));
		}
	}

	return;
}

Map::Map(int nr_rows, int nr_cols, int row_0, int col_0): _row(row_0), _col(col_0), _width(nr_cols), _height(nr_rows), _nbCases(nr_rows * nr_cols), _score(0), _w(newwin(nr_rows, nr_cols, row_0, col_0))
{
	box(this->_w, 0, 0);
	wrefresh(this->_w);

	(void)this->_score;
	(void)this->_nbCases;
	(void)this->_row;
	(void)this->_col;
	this->_cur = std::clock();
	this->_prev = this->_cur;
	this->_nbTurns = 0;
	srand(time(NULL));

	this->_player = PlayerShip();
	this->_player.setXpos(rand() % (this->_width - 12) + 6);
	this->_player.setYpos(this->_height - 2);
	show(this->_player);

	this->_enemies = Squad();

	for (int y = 2 ; y < this->_height - 2 ; y++)
	{
		for (int x = 1 ; x <= 5 ; x++)
		{
			if (rand() % 101 <= 100 / x)
			{
				EnemyShip* enemy1 = new EnemyShip(x, y, 1. / 3., (unsigned int)-1, '>');
				EnemyShip* enemy2 = new EnemyShip(this->_width - x - 1, y, 1. / 3., (unsigned int)-1, '>');
				this->_enemies.push(enemy1);
				this->_enemies.push(enemy2);
				show(*enemy1);
				show(*enemy2);
			}
		}
	}

	this->createNextTurnOfEnemies();
	return;
}

Map::~Map( void )
{
	return;
}

char* Map::getPrintableTime( void )
{
	time_t tmp = this->_cur / (double)CLOCKS_PER_SEC;
	struct tm *time = std::localtime(&tmp);
	strftime(this->_timeStr, 32, "%M.%S", time);
	return this->_timeStr;
}

void Map::updatePlayerStuff( void )
{
	Weapon& tmpWeapon = this->_player.getWeapon();
	for (int i = 0 ; i < tmpWeapon.getNbShoots() ; i++)
	{
		Shoot* tmpShoot = tmpWeapon.getShoot(i);
		if (tmpShoot->getYpos() < 2)
		{
			erase(*tmpShoot);
			tmpWeapon.shootEnd(tmpShoot);
			i--;
			continue;
		}
		bool proof = false;
		for (int j = 0 ; j < this->_enemies.getCount() ; j++)
		{
			ASpaceShip* tmpShip = this->_enemies.getUnit(j);
			if (tmpShip == 0 || tmpShip->getHP() == 0 || (int)tmpShip->getXpos() != (int)tmpShoot->getXpos())
				continue;
			else if ((int)tmpShoot->getYpos() > (int)tmpShip->getYpos() && (int)(tmpShoot->getYpos() + tmpShoot->getDirection()) <= (int)tmpShip->getYpos())
			{
				if ((int)tmpShip->getWeapon().getDamage() > 0)
				{
					tmpShip->takeDamage(tmpWeapon.getDamage());
					this->_score += 10;
				}
				erase(*tmpShoot);
				tmpWeapon.shootEnd(tmpShoot);
				i--;
				proof = true;
				break;
			}
		}
		if (!proof)
			show(*tmpShoot, tmpShoot->getXpos(), tmpShoot->getYpos() + (tmpShoot->getDirection() + 1));
	}
	if (this->_player.getYpos() > 2)
	{
		this->_player.getWeapon().createShoot(this->_player.getXpos(), this->_player.getYpos(), -1., this->_player.getWeapon().getSymbol());
		show(*this->_player.getWeapon().getShoot(this->_player.getWeapon().getNbShoots() - 1));
	}
	return;
}

void Map::updateEnemiesStuff( void )
{
	for (int i = 0 ; i < this->_enemies.getCount() ; i++)
	{
		ASpaceShip* tmpShip = this->_enemies.getUnit(i);
		if (tmpShip == 0)
			continue;
		Weapon& tmpWeapon = tmpShip->getWeapon();
		if (tmpShip->getHP() > 0 && (int)tmpShip->getXpos() == (int)this->_player.getXpos() && (int)tmpShip->getYpos() < (int)this->_player.getYpos() && (int)(tmpShip->getYpos() + tmpShip->getDirection()) >= (int)this->_player.getYpos())
		{
			this->_player.takeDamage(this->_player.getHP());
			return;
		}
		for (int j = 0 ; j < tmpWeapon.getNbShoots() ; j++)
		{
			Shoot* tmpShoot = tmpWeapon.getShoot(j);
			if (tmpShoot == 0)
				continue;
			else if ((int)tmpShoot->getXpos() != (int)this->_player.getXpos())
			{	
				show(*tmpShoot, tmpShoot->getXpos(), tmpShoot->getYpos() + tmpShoot->getDirection());
				continue;
			}
			else if (tmpShoot->getYpos() < this->_height - 2 && (int)tmpShoot->getYpos() < (int)this->_player.getYpos() && (int)(tmpShoot->getYpos() + tmpShoot->getDirection()) >= (int)this->_player.getYpos())
			{
				this->_player.takeDamage(tmpWeapon.getDamage());
				erase(*tmpShoot);
				tmpWeapon.shootEnd(tmpShoot);
				j--;
			}
			else
			{
				show(*tmpShoot, tmpShoot->getXpos(), tmpShoot->getYpos() + tmpShoot->getDirection());
				if (tmpShoot->getYpos() >= this->_height - 3)
				{
					erase(*tmpShoot);
					tmpWeapon.shootEnd(tmpShoot);
					j--;
				}
			}
		}


		double dec = tmpShip->getYpos() + tmpShip->getDirection() - (int)(tmpShip->getYpos() + tmpShip->getDirection());
		show(*tmpShip, tmpShip->getXpos(), dec >= 0.9 ? (int)(tmpShip->getYpos() + tmpShip->getDirection()) + 1 : tmpShip->getYpos() + tmpShip->getDirection() );
		if ((int)tmpShip->getYpos() >= this->_height - 1 || (tmpShip->getHP() <= 0 && tmpWeapon.getNbShoots() <= 0 ))
		{
			erase(*tmpShip);
			this->_enemies.killUnit(tmpShip);
			i--;
		}
	}
	this->createNextTurnOfEnemies();
	return;
}

void Map::infosPrint( Map * info )
{
	std::ostringstream hp, score, time;

	hp << "Hp: " << this->_player.getHP();
	score << "Score: " << this->_score;
	time << "Time: " << this->getPrintableTime();

	wclear(info->getWindow());
	box(info->getWindow(), 0, 0);
	wmove(info->getWindow(), 1, 2);
	wprintw(info->getWindow(), hp.str().c_str());
	wmove(info->getWindow(), 1, 18);
	wprintw(info->getWindow(), score.str().c_str());
	wmove(info->getWindow(), 1, 35);
	wprintw(info->getWindow(), time.str().c_str());
	// info->showMsg(1, 1, hp.str().c_str());
	// info->showMsg(1, 25, score.str().c_str());
	// info->showMsg(1, 40, time.str().c_str());
	info->refresh();

	return;
}

void Map::getUserAction( int ch )
{
	switch (ch)
	{
		case KEY_LEFT:
			for (int i = 0 ; i < this->_enemies.getCount() ; i++)
			{
				ASpaceShip *tmpShip = this->_enemies.getUnit(i);
				if (tmpShip == 0 || tmpShip->getHP() <= 0 || (int)this->_player.getYpos() != (int)tmpShip->getYpos() || (int)this->_player.getYpos() == this->_height - 2)
					continue;
				if ((int)this->_player.getXpos() > (int)tmpShip->getXpos() && (int)(this->_player.getXpos() - 1) <= (int)tmpShip->getXpos())
				{
					this->_player.takeDamage(this->_player.getHP());
					return;
				}
			}
			show(this->_player, this->_player.getXpos() - 1 < 1 ? 1 : this->_player.getXpos() - 1, this->_player.getYpos());
			break;
		case KEY_RIGHT:
			for (int i = 0 ; i < this->_enemies.getCount() ; i++)
			{
				ASpaceShip *tmpShip = this->_enemies.getUnit(i);
				if (tmpShip == 0 || tmpShip->getHP() <= 0 || (int)this->_player.getYpos() != (int)tmpShip->getYpos() || (int)this->_player.getYpos() == this->_height - 2)
					continue;
				if ((int)this->_player.getXpos() < (int)tmpShip->getXpos() && (int)this->_player.getXpos() + 1 >= (int)tmpShip->getXpos())
				{
					this->_player.takeDamage(this->_player.getHP());
					return;
				}
			}
			show(this->_player, this->_player.getXpos() + 1 > this->_width - 2 ? this->_width - 2 : this->_player.getXpos() + 1, this->_player.getYpos());
			break;
		case KEY_UP:
			for (int i = 0 ; i < this->_enemies.getCount() ; i++)
			{
				ASpaceShip *tmpShip = this->_enemies.getUnit(i);
				if (tmpShip == 0 || tmpShip->getHP() <= 0 || (int)this->_player.getXpos() != (int)tmpShip->getXpos() || (int)this->_player.getYpos() == this->_height - 2)
					continue;
				if ((int)this->_player.getYpos() > (int)tmpShip->getYpos() && (int)this->_player.getYpos() - 1 <= (int)tmpShip->getYpos())
				{
					this->_player.takeDamage(this->_player.getHP());
					return;
				}
			}
			show(this->_player, this->_player.getXpos(), this->_player.getYpos() - 1 < 1 ? 1 : this->_player.getYpos() - 1);
			break;
		case KEY_DOWN:
			for (int i = 0 ; i < this->_enemies.getCount() ; i++)
			{
				ASpaceShip *tmpShip = this->_enemies.getUnit(i);
				if (tmpShip == 0 || tmpShip->getHP() <= 0 || (int)this->_player.getXpos() != (int)tmpShip->getXpos() || (int)this->_player.getYpos() == this->_height - 2)
					continue;
				if ((int)this->_player.getYpos() < (int)tmpShip->getYpos() && (int)this->_player.getYpos() + 1 >= (int)tmpShip->getYpos())
				{
					this->_player.takeDamage(this->_player.getHP());
					return;
				}
			}
			show(this->_player, this->_player.getXpos(), this->_player.getYpos() + 1 >= this->_height - 2 ? this->_height - 2 : this->_player.getYpos() + 1);
			break;
		default:
			break;
	}
	return;
}

void Map::run( Map* info )
{
	int ch;
	while (TRUE)
	{
		keypad(this->_w, TRUE);
		nodelay(this->_w, TRUE);
		ch = wgetch(this->_w);
		if (ch == 'q')
		{
			break ;
		}
		
		this->getUserAction(ch);
		
		this->_cur = clock();
		if (this->_cur - this->_prev < Map::timeBeforeUpdate)
		 	continue;
		this->_prev = this->_cur;

		this->updatePlayerStuff();
		this->updateEnemiesStuff();

		if (this->_player.getHP() <= 0)
		{
			wclear(this->_w);
			box(this->_w, 0, 0);
			wmove(this->_w, (this->_height / 2), (this->_width / 2) - 3);
			wprintw(this->_w, "GAME OVER");
			refresh();
			this->infosPrint(info);
			while ((ch = getch()) != 'q') ;
			break;
		}

	 	this->_nbTurns++;
	 	show(this->_player);
	 	this->infosPrint(info);
		refresh();
	}
	return;
}

WINDOW *Map::getWindow() {
	return this->_w;
}

WINDOW *Map::frameResize(Screen const &obj) {
	int h;
	int w;
	getmaxyx(stdscr, h, w);
	if (h != obj.getHeight() || w != obj.getWidth())
	{
		wprintw(this->_w, "SIZE CHANGED");
		//destroy frames and create new ones;
		wborder(this->_w, ' ', ' ', ' ',' ',' ',' ',' ',' ');
		wrefresh(this->_w);
		delwin(this->_w);
		this->_w = newwin(obj.getHeight() - 5, obj.getWidth() - 5, 5, 5);
		box(this->_w, 0, 0);
		wrefresh(this->_w);
	}
	return this->_w;
}

void Map::show(mapElement &x) {
	mvwaddch(this->_w, x.getYpos(), x.getXpos(), x.getSymbol());
}

void Map::erase(mapElement &x) {
	mvwaddch(this->_w, x.getYpos(), x.getXpos(), ' ');
}

void Map::show(mapElement &x, double col_0, double row_0) {
	if((row_0 >= 0 && row_0 < this->_height - 1) && (col_0 >= 0 && col_0 < this->_width - 1)) {
		// Get the element at the target position:
		char target = static_cast<char>mvwinch(_w, row_0, col_0);
		// target will check for the enemy ship or borders
		if (target == '~' || target == '-' || target == '|') {
			return;
		}
		erase(x);
		mvwaddch(this->_w, row_0, col_0, x.getSymbol());
		x.setXpos(col_0);
		x.setYpos(row_0);
	}
	else
		erase(x);
}

void Map::refresh() {
	wrefresh(this->_w);
}

void Map::showMsg(int xpos, int ypos, const char *msg) {
	wmove(this->_w, ypos, xpos);
	wprintw(this->_w, msg);
}
