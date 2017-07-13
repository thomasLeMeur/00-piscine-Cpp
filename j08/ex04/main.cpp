/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:46:16 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/20 12:05:08 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Num.hpp"
#include "Div.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Mul.hpp"
#include "OpenPar.hpp"
#include "ClosePar.hpp"
#include "AToken.hpp"
#include <deque>
#include <vector>
#include <iomanip>

std::string clean(char *str)
{
	std::string s = "";
	while (*str)
	{
		if (*str != ' ' && *str != '\n' && *str != '\t')
			s += *str;
		str++;
	}
	return s;
}

std::string parse(std::string expr)
{
	int pos = 0;
	for (pos = 0 ; pos < expr.size() ; pos++)
		if (!isdigit(expr[pos]) && expr[pos] != '+' && expr[pos] != '-' && expr[pos] != '*' && expr[pos] != '/' && expr[pos] != '(' && expr[pos] != ')')
			return "";

	pos = 0;
	while ((pos = expr.find("(", pos)) < std::string::npos)
	{
		if (pos + 1 != std::string::npos && (expr[pos + 1] == '+' || expr[pos + 1] == '/' || expr[pos + 1] == '*'))
			return "";
		if (pos - 1 >= 0 && isdigit(expr[pos - 1]))
			return "";
		pos++;
	}

	pos = 0;
	while ((pos = expr.find(")", pos)) < std::string::npos)
	{
		if (pos - 1 >= 0 && (expr[pos - 1] == '+' || expr[pos - 1] == '-' || expr[pos - 1] == '/' || expr[pos - 1] == '*'))
			return "";
		if (pos + 1 != std::string::npos && isdigit(expr[pos + 1]))
			return "";
		pos++;
	}


	if (expr.find("++") != std::string::npos || expr.find("-+") != std::string::npos || expr.find("---") != std::string::npos ||
		expr.find("+*") != std::string::npos || expr.find("-*") != std::string::npos || expr.find("+/") != std::string::npos || expr.find("-/") != std::string::npos ||
		expr.find("**") != std::string::npos || expr.find("*+") != std::string::npos || expr.find("*/") != std::string::npos || expr.find("//") != std::string::npos ||
		expr.find("/+") != std::string::npos || expr.find("/*") != std::string::npos || expr.find("/--") != std::string::npos || expr.find("+--") != std::string::npos ||
		expr.find("*--") != std::string::npos || expr.find(")(") != std::string::npos || expr.find("()") != std::string::npos)
		return "";

	pos = 0;
	while ((pos = expr.find("+-", pos)) != std::string::npos)
	{
		expr = expr.replace(pos, 2, "-");
		pos++;
	}

	pos = 0;
	while ((pos = expr.find("--", pos)) != std::string::npos)
	{
		expr = expr.replace(pos, 2, "+");
		pos++;
	}

	int nb = 0;
	for (pos = 0 ; pos < expr.size() ; pos++)
	{
		if (expr[pos] == '(') nb++;
		else if (expr[pos] == ')') nb--;
		if (nb < 0)
			return "";
	}
	if (nb)
		return "";

	if (expr[0] == '+' || expr[0] == ')' || expr[0] == '/' || expr[0] == '*' ||
		expr[expr.size() - 1] == '+' || expr[expr.size() - 1] == '(' || expr[expr.size() - 1] == '/' || expr[expr.size() - 1] == '*')
		return "";

	return expr;
}

std::deque<AToken *> shunting_yard(std::string expr)
{
	std::string		val = "";
	std::deque<AToken *> stack;
	std::deque<AToken *> ops;

	std::cout << "Tokens :";

	for (int i = 0; i < expr.length(); i++)
	{
		if ((expr[i] >= '0' && expr[i] <= '9') || (expr[i] == '-' && (i == 0 || expr[i - 1] == '*' || expr[i - 1] == '/' || expr[i - 1] == '(')))
		{
			if (i == 0 || val.length() == 0 || (val[val.length() - 1] >= '0' && val[val.length() - 1] <= '9') || val[val.length() - 1] == '-')
			{
				val += expr[i];
			}
			else
			{
				stack.push_back(new Num(atoi(val.c_str())));
				std::cout << " " << *dynamic_cast<Num *>(stack.back());
				val = expr[i];
			}
		}
		else if (expr[i] == '/' || expr[i] == '*')
		{
			if (val != "")
			{
				stack.push_back(new Num(atoi(val.c_str())));
				std::cout << " " << *dynamic_cast<Num *>(stack.back());
			}
			if (dynamic_cast<Div *>(ops.back()) != NULL || dynamic_cast<Mul *>(ops.back()) != NULL)
			{
				stack.push_back(ops.back());
				ops.pop_back();
			}
			if (expr[i] == '/')
			{
				ops.push_back(new Div());
				std::cout << " " << *dynamic_cast<Div *>(ops.back());
			}
			else
			{
				ops.push_back(new Mul());
				std::cout << " " << *dynamic_cast<Mul *>(ops.back());
			}
			val = "";
		}
		else if (expr[i] == '+' || expr[i] == '-')
		{
			if (val != "")
			{
				stack.push_back(new Num(atoi(val.c_str())));
				std::cout << " " << *dynamic_cast<Num *>(stack.back());
			}
			while (ops.size() > 0 && (dynamic_cast<Div *>(ops.back()) != NULL || dynamic_cast<Mul *>(ops.back()) != NULL))
			{
				stack.push_back(ops.back());
				ops.pop_back();
			}
			if (expr[i] == '+')
			{
				ops.push_back(new Add());
				std::cout << " " << *dynamic_cast<Add *>(ops.back());
			}
			else
			{
				ops.push_back(new Sub());
				std::cout << " " << *dynamic_cast<Sub *>(ops.back());
			}
			val = "";
		}
		else if (expr[i] == '(')
		{
			if (val != "" && val != "-")
			{
				stack.push_back(new Num(atoi(val.c_str())));
				std::cout << " " << *dynamic_cast<Num *>(stack.back());
			}
			else if (val == "-")
			{
				ops.push_back(new Sub());
				std::cout << " " << *dynamic_cast<Sub *>(ops.back());
			}
			else if (val != "")
			{
				stack.push_back(new Num(atoi(val.c_str())));
				std::cout << " " << *dynamic_cast<Num *>(stack.back());
			}
			ops.push_back(new OpenPar());
			std::cout << " ParOpen";
			val = "";
		}
		else if (expr[i] == ')')
		{
			if (val != "")
			{
				stack.push_back(new Num(atoi(val.c_str())));
				std::cout << " " << *dynamic_cast<Num *>(stack.back());
			}
			std::cout << " ParClose";
			while (dynamic_cast<OpenPar *>(ops.back()) == NULL)
			{
				stack.push_back(ops.back());
				ops.pop_back();
			}
			delete ops.back();
			ops.pop_back();
			val = "";
		}
	}
	std::cout << "END :";
	if (val != "")
	{
		stack.push_back(new Num(atoi(val.c_str())));
		std::cout << " " << *dynamic_cast<Num *>(stack.back());
	}
	for (unsigned int i = ops.size() ; i > 0 ; i--)
	{
		stack.push_back(ops[i - 1]);
	}

	std::cout << std::endl;

	return stack;
}

int polak( std::deque<AToken *>  expr )
{
	std::cout << "PostFix :";
	for (unsigned int i = 0 ; i < expr.size() ; i++)
	{
		if (dynamic_cast<Add *>(expr[i]) != NULL)
			std::cout << " " << *dynamic_cast<Add *>(expr[i]);
		else if (dynamic_cast<Sub *>(expr[i]) != NULL)
			std::cout << " " << *dynamic_cast<Sub *>(expr[i]);
		else if (dynamic_cast<Div *>(expr[i]) != NULL)
			std::cout << " " << *dynamic_cast<Div *>(expr[i]);
		else if (dynamic_cast<Mul *>(expr[i]) != NULL)
			std::cout << " " << *dynamic_cast<Mul *>(expr[i]);
		else if (dynamic_cast<Num *>(expr[i]) != NULL)
			std::cout << " " << *dynamic_cast<Num *>(expr[i]);
	}
	std::cout << std::endl;

	std::vector<int> tab;

	for (unsigned int i = 0 ; i < expr.size() ; i++)
	{
		std::cout << "I ";
		
		if (dynamic_cast<Add *>(expr[i]) != NULL)
		{
			tab[tab.size() - 2] = tab[tab.size() - 2] + tab[tab.size() - 1];
			tab.pop_back();
			std::cout << std::left << *dynamic_cast<Add *>(expr[i]) << "  | OP ";
		}
		else if (dynamic_cast<Sub *>(expr[i]) != NULL)
		{
			tab[tab.size() - 2] = tab[tab.size() - 2] - tab[tab.size() - 1];
			tab.pop_back();
			std::cout << std::left << *dynamic_cast<Sub *>(expr[i]) << "  | OP ";
		}
		else if (dynamic_cast<Mul *>(expr[i]) != NULL)
		{
			tab[tab.size() - 2] = tab[tab.size() - 2] * tab[tab.size() - 1];
			tab.pop_back();
			std::cout << std::left << *dynamic_cast<Mul *>(expr[i]) << "  | OP ";
		}
		else if (dynamic_cast<Div *>(expr[i]) != NULL)
		{
			if (tab[tab.size() - 1] == 0)
			{
				std::cout << "Division by zero" << std::endl;
				std::exit(1);
			}
			tab[tab.size() - 2] = tab[tab.size() - 2] / tab[tab.size() - 1];
			tab.pop_back();
			std::cout << std::left << *dynamic_cast<Div *>(expr[i]) << "  | OP ";
		}
		else
		{
			tab.push_back(expr[i]->getVal());
			std::cout << std::left << *dynamic_cast<Num *>(expr[i]) << " | OP ";
		}

		std::cout << std::setw(9);
		expr[i]->printType();
		std::cout << " | ST";
		for (unsigned int j = tab.size() ; j > 0 ; j--)
			std::cout << " " << tab[j - 1];
		std::cout << "]" << std::endl;
	}

	for (unsigned int i = 0 ; i < expr.size() ; i++)
		delete expr[i];

	return tab[0];
}

int main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "Usage: ./eval_expr \"expr\"" << std::endl;
	else
	{
		std::string expr(clean(av[1]));

		if (expr == "")
			std::cout << "The argument have to contain some characters" << std::endl;
		else
		{
			expr = parse(expr);
			if (expr == "" || expr == "(" || expr == ")" || expr == "+" || expr == "-" || expr == "--" || expr == "*" || expr == "/")
				std::cout << "An error occured in the parser, please check your syntax" << std::endl;
			else
			{
				std::cout << expr << std::endl;
				int val = polak(shunting_yard(expr));
				std::cout << "Result : " << val << std::endl;
			}
		}
	}
	return (0);
}
