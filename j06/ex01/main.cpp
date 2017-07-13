/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:31:45 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/17 12:49:17 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <climits>

struct Data { std::string s1; int n; std::string s2; };

void * serialize( void )
{
	Data *dat = new Data;

	dat->s1 = "";
	dat->s2 = "";
	for (int i = 0 ; i < 8 ; i++)
	{
		char c = rand() % 62;
		if (c < 10) c += '0';
		else if (c < 36) c = c - 10 + 'a';
		else c = c - 36 + 'A';
		dat->s1 += c;
	}
	dat->n = rand() % UINT_MAX;
	for (int i = 0 ; i < 8 ; i++)
	{
		char c = rand() % 62;
		if (c < 10) c = c + '0';
		else if (c < 36) c = c - 10 + 'a';
		else c = c - 36 + 'A';
		dat->s2 += c;
	}

	std::cout << "Data created : s1='" << dat->s1 << "', n=" << dat->n << ", s2='" << dat->s2 << "'" << std::endl;
	return dat;
}

Data * deserialize( void * raw )
{
	return reinterpret_cast<Data *>(raw);
}

int main(void)
{
	srand(time(NULL));

	void * mem = serialize();
	Data *dat = deserialize(mem);

	std::cout << "Data deserialized : s1='" << dat->s1 << "', n=" << dat->n << ", s2='" << dat->s2 << "'" << std::endl;

	delete dat;

	return 0;
}
