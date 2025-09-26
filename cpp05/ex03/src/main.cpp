/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:46:37 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/09 15:41:37 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ansi_colors.hpp"

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );

int main()
{
	Intern	intern;
	print_test_name( "Intern makes a shrubbery creation form" );
	{
		try
		{
			auto	form = intern.makeForm( "shrubbery creation", "Company garden" );
			std::cout << "\n";
			std::cout << *form;
			delete form;
		}
		catch ( std::exception &e ) {}
	}
	print_test_name( "Intern makes a robotomy request form" );
	{
		try
		{
			auto	form = intern.makeForm( "robotomy request", "Frodo Baggins" );
			std::cout << "\n";
			std::cout << *form;
			delete form;
		}
		catch ( std::exception &e ) {}
	}
	print_test_name( "Intern makes a presidential pardon form" );
	{
		try
		{
			auto	form = intern.makeForm( "presidential pardon", "Gollum" );
			std::cout << "\n";
			std::cout << *form;
			delete form;
		}
		catch ( std::exception &e ) {}
	}
	print_test_name( "Intern gets confused" );
	{
		try
		{
			auto	form = intern.makeForm( "Zebra tooth acne removal", "Zappa" );
			std::cout << "\n";
			std::cout << *form;
			delete form;
		}
		catch ( std::exception &e ) {}
	}
	std::cout << std::endl;
	return 0;
}

/* -------------------------------------------------------------------------- */

static void print_test_name( std::string str )
{

	for ( char &c : str )
		c = std::toupper( c );

	size_t width = str.length() + 10;

	std::string separator = n_chars( '-', width );
	std::cout << "\n" C_HI_Y << separator << "\n";
	std::cout << "**** " << str << " ****";
	std::cout << "\n" << separator << C_RST "\n";
	std::cout << std::endl;
}

static std::string n_chars( char c, size_t n )
{
	std::string str = "";
	while ( n-- )
		str += c;
	return str;
}
