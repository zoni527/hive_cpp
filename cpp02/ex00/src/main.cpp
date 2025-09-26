/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:46:37 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/05 09:49:12 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "ansi_colors.hpp"
#include <iostream>

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );

int main() {

	print_test_name( "Subject's main (with better formatting)" );
	{
		Fixed a;
		std::cout << "\n";
		Fixed b( a );
		std::cout << "\n";
		Fixed c;
		std::cout << "\n";
		c = b;
		std::cout << "\n";
		std::cout << a.getRawBits() << std::endl;
		std::cout << "\n";
		std::cout << b.getRawBits() << std::endl;
		std::cout << "\n";
		std::cout << c.getRawBits() << std::endl;
		std::cout << "\n";
	}
	print_test_name( "Extra test: set raw bits" );
	{
		Fixed a;
		std::cout << "\na.getRawbits(): " << a.getRawBits() << "\n\n";
		a.setRawBits( 42042420 );
		std::cout << "\na.getRawbits(): " << a.getRawBits() << "\n\n";
	}
	std::cout << std::endl;
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
