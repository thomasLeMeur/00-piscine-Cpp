/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 10:38:48 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/20 15:12:29 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <queue>
#include <iostream>
#include <fstream>
#include "AMindOpen.hpp"
#include "IncrVal.hpp"
#include "IncrPtr.hpp"
#include "DecrVal.hpp"
#include "DecrPtr.hpp"
#include "GetVal.hpp"
#include "PutVal.hpp"

/*void solve( std::queue<AMindOpen *> & q, int & ind)
{
	std::deque<AMindOpen *> d;
	std::queue<AMindOpen *> t;
	while (q.size())
	{
		d.push_back(q.front());
		t.push(q.front());
		q.pop();
	}
	for (unsigned int i = 0 ; i < d.size() ; i++)
		d[i]->_instrs = q;
	while (ind != (int)d.size())
	{
		std::cout << ind << " : ";
		ind = d[ind]->execute();
	}
	return;
}*/

std::string checkLineAndFillQueue( std::string const & line, std::string & instrs)
{
	char expected[8] = { '0', '1', '2', '3', '4', '5', '6', '7' };

	for (unsigned int i = 0 ; i < line.size() ; i++)
		for (int j = 0 ; j < 8 ; j++)
			if (line[i] == expected[j])
				instrs += line[i];
	return instrs;
}

std::string explode( char *s)
{
	int i = 0;
	std::string str = "";
	std::vector<int> tab(1, 0);
	char *ref = s;

	while (*s)
	{
		if (*s == '0')
		{
			if (++i >= (int)tab.size()) tab.push_back(0);
			str += *s;
		}
		else if (*s == '1')
		{
			if (--i < 0)
			{
				std::cout << "Invalid Program: you're kinding me !" << std::endl;
				std::exit(0);
			}
			str += *s;
		}
		else if (*s == '2') tab[i]++, str += *s;
		else if (*s == '3') tab[i]--, str += *s;
		else if (*s == '4') str += *s;
		else if (*s == '5') str += *s;
		else if (*s == '6' && tab[i] == 0)
		{
			int nbO = 0, nbC = 0;
			char *t = s;
			while (*t)
			{
				if (*t == '7') nbC++;
				else if (*t == '6') nbO++;
				if (nbC == nbO) break;
				t++;
			}
			if (!*t)
			{
				std::cout << "No matching 7" << std::endl;
				std::exit(0);
			}
			s = t;
		}
		else if (*s == '7' && tab[i] != 0)
		{
			int nbO = 0, nbC = 0;
			char *t = s;
			while (t >= ref)
			{
				if (*t == '7') nbC++;
				else if (*t == '6') nbO++;
				if (nbC == nbO) break;
				t--;
			}
			if (t < ref)
			{
				std::cout << "No matching 6" << std::endl;
				std::exit(0);
			}
			s = t;
		}
		s++;
	}
	return str;
}

void solve( char *s)
{
	int i = 0;
	std::vector<int> tab(1, 0);

	while (*s)
	{
		if (*s == '0')
		{
			if (++i >= (int)tab.size()) tab.push_back(0);
		}
		else if (*s == '1') --i;
		else if (*s == '2')
			tab[i]++;
		else if (*s == '3')
			tab[i]--;
		else if (*s == '4') std::cout << static_cast<char>(tab[i]) << " ";
		s++;
	}
	return;
}

void enqueue( std::string const & s, std::queue<AMindOpen *> & q, std::vector<int> & tab, int & ind )
{
	char expected[6] = { '0', '1', '2', '3', '4', '5' };

	for (unsigned int i = 0 ; i < s.size() ; i++)
		for (int j = 0 ; j < 8 ; j++)
			if (s[i] == expected[j])
			{
				if (j == 0) q.push( new IncrPtr(tab, ind));
				else if (j == 1) q.push( new DecrPtr(tab, ind));
				else if (j == 2) q.push( new IncrVal(tab, ind));
				else if (j == 3) q.push( new DecrVal(tab, ind));
				else if (j == 4) q.push( new PutVal(tab, ind));
				else if (j == 5) q.push( new GetVal(tab, ind));
				break;
			}
	return;
}

int main( int ac, char **av )
{
	if (ac != 2)
		std::cout << "Usage: ./mindopen filename" << std::endl;
	else
	{
		std::ifstream file(av[1]);
		if (file.fail())
			std::cout << "Can't open the file" << std::endl;
		else
		{
			std::queue<AMindOpen *> q;
			std::string line, instrs = "";
			int ind = 0;

			std::getline(file, line);
			while (!file.eof())
			{
				instrs = checkLineAndFillQueue(line, instrs);
				std::getline(file, line);
			}
			instrs = checkLineAndFillQueue(line, instrs);

			instrs = explode(const_cast<char *>(instrs.c_str()));

			std::vector<int> tab(std::count(instrs.begin(), instrs.end(), '0'), 0);
			enqueue(instrs, q, tab, ind);

			while (!q.empty())
			{
				q.front()->execute();
				delete q.front();
				q.pop();
			}
		}
		file.close();
	}
	return 0;
}
