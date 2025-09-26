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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ansi_colors.hpp"
#include "chrono"

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );

int main()
{
	print_test_name( "Let's make a shrubbery" );
	{
		ShrubForm	shrubForm( "Hive" );
		std::cout << shrubForm << "\n";

		Bureaucrat	bob( "Bob", 150 );
		std::cout << bob;
		bob.signForm( shrubForm );
		bob.executeForm( shrubForm );
		std::cout << "\n";

		Bureaucrat	mat( "Mat", shrubForm.getGradeToSign() );
		std::cout << mat;
		mat.signForm( shrubForm );
		mat.executeForm( shrubForm );
		std::cout << "\n";

		Bureaucrat	god( "God", shrubForm.getGradeToExec() );
		std::cout << god;
		god.signForm( shrubForm );
		god.executeForm( shrubForm );
	}
	std::srand( std::time( nullptr ) );
	print_test_name( "Let's make a robot" );
	{
		RoboForm	roboForm( "Roni" );
		std::cout << roboForm << "\n";

		Bureaucrat	bob( "Bob", 150 );
		std::cout << bob;
		bob.signForm( roboForm );
		bob.executeForm( roboForm );
		std::cout << "\n";

		Bureaucrat	mat( "Mat", roboForm.getGradeToSign() );
		std::cout << mat;
		mat.signForm( roboForm );
		mat.executeForm( roboForm );
		std::cout << "\n";

		Bureaucrat	god( "God", roboForm.getGradeToExec() );
		std::cout << god;
		god.signForm( roboForm );
		god.executeForm( roboForm );
	}
	print_test_name( "Let's pardon somebody" );
	{
		PrezForm	prezForm( "The Zodiac Killer" );
		std::cout << prezForm << "\n";

		Bureaucrat	bob( "Bob", 150 );
		std::cout << bob;
		bob.signForm( prezForm );
		bob.executeForm( prezForm );
		std::cout << "\n";

		Bureaucrat	mat( "Mat", prezForm.getGradeToSign() );
		std::cout << mat;
		mat.signForm( prezForm );
		mat.executeForm( prezForm );
		std::cout << "\n";

		Bureaucrat	god( "God", prezForm.getGradeToExec() );
		std::cout << god;
		god.signForm( prezForm );
		god.executeForm( prezForm );
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
