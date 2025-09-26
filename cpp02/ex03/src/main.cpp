/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:46:37 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/09 19:45:39 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "ansi_colors.hpp"
#include <iostream>

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );
static void			test( Point a, Point b, Point c, Point p );

int main() {

	print_test_name( "Triangle 1: 0,0 0,10 10,0" );
	{
		Point	a( 0, 0);
		Point	b( 0, 10);
		Point	c( 10, 0);
		{
			Point	p( 0, 0 );
			test( a, b, c, p );
		}
		{
			Point	p( 0, 10);
			test( a, b, c, p );
		}
		{
			Point	p( 10, 0);
			test( a, b, c, p );
		}
		{
			Point	p( 0, 1);
			test( a, b, c, p );
		}
		{
			Point	p( 1, 1);
			test( a, b, c, p );
		}
		{
			Point	p( 11, 10);
			test( a, b, c, p );
		}
		{
			Point	p( 2, 4);
			test( a, b, c, p );
		}
		{
			Point	p( 0.58, 5.67);
			test( a, b, c, p );
		}
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

static void			test( Point a, Point b, Point c, Point p ) {
	std::cout << "Point: " << p.getX() << ", " << p.getY() << "\n";
	if ( bsp( a, b, c, p ) )
		std::cout << C_HI_G "Point is inside triangle" C_RST << "\n";
	else
		std::cout << C_HI_R "Point is outside triangle" C_RST << "\n";
	std::cout << std::endl;
}
