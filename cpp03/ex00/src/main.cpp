/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:46:37 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/09 11:56:15 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ansi_colors.hpp"
#include <iostream>

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );
static void print_info( ClapTrap const &a );

int main() {

	print_test_name( "Test: default costructor" );
	{
		ClapTrap a;
		std::cout << "\n";
		print_info( a );
		std::cout << "\n";
	}
	print_test_name( "Test: string constructor" );
	{
		ClapTrap a( "DerpyDerp" );
		std::cout << "\n";
		print_info( a );
		std::cout << "\n";
	}
	print_test_name( "Test: copy constructor" );
	{
		ClapTrap a( "First" );
		std::cout << "\n";
		print_info( a );
		std::cout << "\n";
		ClapTrap b( a );
		std::cout << "\n";
		print_info( b );
		std::cout << "\n";
	}
	print_test_name( "Test: copy assignment operator" );
	{
		ClapTrap a( "First" ), b( "Second" );
		std::cout << "\n";
		print_info( a );
		print_info( b );
		std::cout << "\n";
		a = b;
		std::cout << "\n";
		print_info( a );
		print_info( b );
		std::cout << "\n";
		b.setHP( 0 );
		print_info( a );
		print_info( b );
		std::cout << "\n";
	}
	print_test_name( "Test: attack" );
	{
		ClapTrap a;
		std::cout << "\n";
		print_info( a );
		std::cout << "\n";
		a.attack( "YOU" );
		std::cout << "\n";
		print_info( a );
		std::cout << "\n";
		a.setHP( 0 );
		a.attack( "YOU" );
		std::cout << "\n";
		a.setHP( 1 );
		a.setEP( 0 );
		a.attack( "YOU" );
		std::cout << "\n";
	}
	print_test_name( "Test: takeDamage" );
	{
		ClapTrap a;
		std::cout << "\n";
		a.takeDamage( 5 );
		std::cout << "\n";
		a.setHP( 10 );
		a.takeDamage( -1 );
		a.takeDamage( 1 );
		std::cout << "\n";
		a.setHP( 10 );
		a.takeDamage( 6 );
		std::cout << "\n";
	}
	print_test_name( "Test: beRepaired" );
	{
		ClapTrap a;
		std::cout << "\n";
		a.setHP( 0 );
		a.beRepaired( 5 );
		std::cout << "\n";
		a.beRepaired( -1 );
		std::cout << "\n";
	}
	std::cout << std::endl;
	return 0;
}

// ------------------------------------------------------------ static functions

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

static void print_info( ClapTrap const &a ) {
	std::cout
		<< "Name: " << a.getName()
		<< ", HP: " << a.getHP()
		<< ", EP: " << a.getEP()
		<< ", AD: " << a.getAD() << std::endl;
}
