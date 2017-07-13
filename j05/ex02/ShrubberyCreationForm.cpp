/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/XX/XX XX:XX:XX by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("ShrubberyCreationForm", 145, 137), _target("")
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const & target ) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & other ) : Form("ShrubberyCreationForm", 145, 137), _target(other._target)
{
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	return;
}


ShrubberyCreationForm& ShrubberyCreationForm::operator=( ShrubberyCreationForm const & other )
{
	(void)other;
	return *this;
}

bool ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	try
	{
		this->isExecutable(executor);

		std::string outname(this->_target + "_shrubbery");
		std::ofstream out(outname.c_str());
		if (out.good())
		{
			out << "                                               ." << std::endl;
			out << "                                    .         ;  " << std::endl;
			out << "       .              .              ;%     ;;   " << std::endl;
			out << "        ,           ,                :;%  %;   " << std::endl;
			out << "         :         ;                   :;%;'     .,   " << std::endl;
			out << ",.        %;     %;            ;        %;'    ,;" << std::endl;
			out << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
			out << "   %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
			out << "    ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
			out << "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
			out << "        `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
			out << "           `:%;.  :;bd%;          %;@%;'" << std::endl;
 			out << "             `@%:.  :;%.         ;@@%;'   " << std::endl;
			out << "               `@%.  `;@%.      ;@@%;         " << std::endl;
			out << "                 `@%%. `@%%    ;@@%;        " << std::endl;
			out << "                   ;@%. :@%%  %@@%;       " << std::endl;
			out << "                     %@bd%%%bd%%:;     " << std::endl;
 			out << "                       #@%%%%%:;;" << std::endl;
			out << "                       %@@%%%::;" << std::endl;
			out << "                       %@@@%(o);  . '         " << std::endl;
			out << "                       %@@@o%;:(.,'         " << std::endl;
 			out << "                   `.. %@@@o%::;         " << std::endl;
			out << "                      `)@@@o%::;         " << std::endl;
 			out << "                       %@@(o)::;        " << std::endl;
			out << "                      .%@@@@%::;         " << std::endl;
 			out << "                      ;%@@@@%::;.          " << std::endl;
 			out << "                      ;%@@@@%%:;;;. " << std::endl;
 			out << "                   ...;%@@@@@%%:;;;;,.." << std::endl;
		}

		out.close();
		return true;
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Form::FormUnsignedException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return false;
}