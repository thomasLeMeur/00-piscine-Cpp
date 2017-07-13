/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:46:16 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/12 18:35:55 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Fixed.hpp"

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
		if (!isdigit(expr[pos]) && expr[pos] != '+' && expr[pos] != '-' && expr[pos] != '*' && expr[pos] != '/' && expr[pos] != '(' && expr[pos] != ')' && expr[pos] != '.')
			return "";

	pos = 0;
	while ((pos = expr.find("(", pos)) < std::string::npos)
	{
		if (pos + 1 != std::string::npos && (expr[pos + 1] == '+' || expr[pos + 1] == '/' || expr[pos + 1] == '*'))
			return "";
		if (pos - 1 >= 0 && (isdigit(expr[pos - 1]) || expr[pos - 1] == '.'))
			return "";
		pos++;
	}

	pos = 0;
	while ((pos = expr.find(")", pos)) < std::string::npos)
	{
		if (pos - 1 >= 0 && (expr[pos - 1] == '+' || expr[pos - 1] == '-' || expr[pos - 1] == '/' || expr[pos - 1] == '*'))
			return "";
		if (pos + 1 != std::string::npos && (isdigit(expr[pos + 1]) || expr[pos + 1] == '.'))
			return "";
		pos++;
	}

	pos = 0;
	while ((pos = expr.find(".", pos)) != std::string::npos)
	{
		if (pos == 0 || !isdigit(expr[pos - 1]))
		{
			if (pos == expr.size() - 1 || !isdigit(expr[pos + 1]))
				return "";
			expr = expr.replace(pos, 1, "0.");
			pos += 2;
		}
		else if (pos + 1 != std::string::npos && !isdigit(expr[pos + 1]))
		{
			if (expr[pos + 1] == '.')
				return "";
			expr = expr.replace(pos, 1, "");
		}
		else
		{
			int tmp;
			for (tmp = pos + 1 ; tmp != expr.size() && isdigit(expr[tmp]) ; tmp++) ;
			if (tmp != expr.size() && expr[tmp] == '.')
				return "";
			pos++;
		}
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

std::string shunting_yard(std::string expr)
{
	std::string		stack = "";
	std::string		ops = "";
	for (int i = 0; i < expr.length(); i++)
	{
		if ((expr[i] >= '0' && expr[i] <= '9') || expr[i] == '.' || (expr[i] == '-' && (i == 0 || expr[i - 1] == '*' || expr[i - 1] == '/' || expr[i - 1] == '(')))
		{
			if ((stack[stack.length() - 1] >= '0' && stack[stack.length() - 1] <= '9') || stack[stack.length() - 1] == '.' || i == 0 || stack[stack.length() - 1] == '-')
			{
				stack += expr[i];
			}
			else
			{
				stack += " ";
				stack += expr[i];
			}
		}
		else if (expr[i] == '/' || expr[i] == '*')
		{
			stack += " ";
			if (ops[ops.length() - 1] == '/' || ops[ops.length() - 1] == '*')
			{
				stack += ops[ops.length() - 1];
				ops[ops.length() - 1] = expr[i];
			}
			else
				ops += expr[i];
		}
		else if (expr[i] == '+' || expr[i] == '-')
		{
			stack += " ";
			while (ops[ops.length() - 1] == '/' || ops[ops.length() - 1] == '*')
			{
				stack += ops[ops.length() - 1];
				ops.erase(ops.length() - 1, 1);
			}
			ops += expr[i];
		}
		if (expr[i] == '(')
			ops += expr[i];
		if (expr[i] == ')')
		{
			while (ops[ops.length() - 1] != '(')
			{
				stack += " ";
				stack += ops[ops.length() - 1];
				ops.erase(ops.length() - 1, 1);
			}
			ops.erase(ops.length() - 1, 1);
		}
	}
	while (ops.length() > 0)
	{
		stack += " ";
		stack += ops[ops.length() - 1];
		ops.erase(ops.length() - 1, 1);
	}
	stack += " ";
	return stack;
}

Fixed polak( std::string expr )
{
	int nbW = 1;
	for (int i = 0 ; i < expr.size() ; i++)
		if (expr[i] == ' ')
			nbW++;
	int ind = 0;
	float tab[nbW];

	std::istringstream in(expr);
	std::string e = "e";

	in >> e;
	while (e == " " || in.good())
	{
		if (e == "+")
		{
			ind = (ind - 2 < 0) ? 0 : ind - 2;
			tab[ind] = (Fixed(tab[ind]) + Fixed(tab[ind + 1])).toFloat();
			ind++;
		}
		else if (e == "-")
		{
			ind = (ind - 2 < 0) ? 0 : ind - 2;
			tab[ind] = (Fixed(tab[ind]) - Fixed(tab[ind + 1])).toFloat();
			ind++;
		}
		else if (e == "*")
		{
			ind = (ind - 2 < 0) ? 0 : ind - 2;
			tab[ind] = (Fixed(tab[ind]) * Fixed(tab[ind + 1])).toFloat();
			ind++;
		}
		else if (e == "/")
		{
			ind = (ind - 2 < 0) ? 0 : ind - 2;
			if (Fixed(tab[ind + 1]).toFloat() == 0.f)
			{
				std::cout << "Division by zero" << std::endl;
				std::exit(1);
			}
			tab[ind] = (Fixed(tab[ind]) / Fixed(tab[ind + 1])).toFloat();
			ind++;
		}
		else
		{
			tab[ind] = Fixed((float)atof(e.c_str())).toFloat();
			ind++;
		}
		in >> e;
	}
	return Fixed(tab[0]);
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
			if (expr == "" || expr == "(" || expr == ")" || expr == "+" || expr == "-" || expr == "--" || expr == "*" || expr == "/" || expr == ".")
				std::cout << "An error occured in the parser, please check your syntax" << std::endl;
			else
				std::cout << polak(shunting_yard(expr)).toFloat() << std::endl;
		}
	}
	return (0);
}
