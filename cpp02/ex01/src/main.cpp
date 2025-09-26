/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:46:37 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/05 22:53:09 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "ansi_colors.hpp"
#include <iostream>

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );

int main() {

	print_test_name( "Subject's main (with better formatting)" );
	// -------------------------------------------------------------------------
	{
		Fixed a;
		std::cout << "\n";
		Fixed const b( 10 );
		std::cout << "\n";
		Fixed const c( 42.42f );
		std::cout << "\n";
		Fixed const d( b );
		std::cout << "\n";
		a = Fixed( 1234.4321f );
		std::cout << "\n";
		std::cout << "a is " << a << "\n";
		std::cout << "b is " << b << "\n";
		std::cout << "c is " << c << "\n";
		std::cout << "d is " << d << "\n";
		std::cout << "a is " << a.toInt() << " as integer" << "\n";
		std::cout << "b is " << b.toInt() << " as integer" << "\n";
		std::cout << "c is " << c.toInt() << " as integer" << "\n";
		std::cout << "d is " << d.toInt() << " as integer" << "\n\n";
	}
	std::cout << std::endl;
	// -------------------------------------------------------------------------
	return 0;
}

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
