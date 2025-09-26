/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:46:37 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:15:32 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ansi_colors.hpp"

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );

int main()
{
	print_test_name( "Default constructor" );
	{
		Bureaucrat	def;
		std::cout << def;
	}
	print_test_name( "Parameterized constructor" );
	{
		Bureaucrat	winston( "Winston Smith", 42 );
		std::cout << winston;
	}
	print_test_name( "Copy constructor" );
	{
		Bureaucrat	original( "Ollie", 123 );
		Bureaucrat	copy( original );
		std::cout << original << copy;
	}
	print_test_name( "This bureaucrat is too weak" );
	{
		try
		{
			Bureaucrat	bob( "Bob", 151 );
		}
		catch ( std::exception &e )
		{
			std::cout << e.what() << std::endl;
		}
	}
	print_test_name( "This bureaucrat is too powerful" );
	{
		try
		{
			Bureaucrat	bob( "Bob", 0 );
		}
		catch ( std::exception &e )
		{
			std::cout << e.what() << std::endl;
		}
	}
	print_test_name( "Incrementing" );
	{
		try
		{
			Bureaucrat	bob( "Bob", 3 );
			bob.incrementGrade();
			std::cout << bob;
			bob.incrementGrade();
			std::cout << bob;
			bob.incrementGrade();
			std::cout << bob;
		}
		catch ( std::exception &e )
		{
			std::cout << e.what() << std::endl;
		}
	}
	print_test_name( "Decrementing" );
	{
		try
		{
			Bureaucrat	bob( "Bob", 148 );
			bob.decrementGrade();
			std::cout << bob;
			bob.decrementGrade();
			std::cout << bob;
			bob.decrementGrade();
			std::cout << bob;
		}
		catch ( std::exception &e )
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	return 0;
}

/* -------------------------------------------------------------------------- */

static void print_test_name( std::string str ) {

	for ( char &c : str )
		c = std::toupper( c );

	size_t width = str.length() + 10;

	std::string separator = n_chars( '-', width );
	std::cout << "\n" C_HI_Y << separator << "\n";
	std::cout << "**** " << str << " ****";
	std::cout << "\n" << separator << C_RST "\n";
	std::cout << std::endl;
}

static std::string n_chars( char c, size_t n ) {
	std::string str = "";
	while ( n-- )
		str += c;
	return str;
}
