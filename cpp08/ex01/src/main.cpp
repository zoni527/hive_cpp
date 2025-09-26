/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:40:48 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/22 13:42:53 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>
#include <iostream>
#include <deque>
#include <array>
#include <random>

#define BIG_NUMBER	30000
#define XSTR(a)		STR(a)
#define STR(a)		#a

#define C_HI_Y	"\033[0;93m\001"
#define C_RST	"\033[0m\002"

static void			subjectsMain();
static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );

int	main()
{
	print_test_name( "Subject's main" );
	subjectsMain();
	print_test_name( "Addnumber throw" );
	{
		try
		{
			Span	s( 0 );
			s.print();
			s.addNumber( 1 );
		}
		catch ( std::exception const &e )
		{
			std::cout << e.what() << '\n';
		}
		try
		{
			Span	s( 3 );

			s.addNumber( 1 );
			s.print();
			s.addNumber( 2 );
			s.print();
			s.addNumber( 3 );
			s.print();
			s.addNumber( 4 );
			s.print();
		}
		catch ( std::exception const &e )
		{
			std::cout << e.what() << '\n';
		}
	}
	print_test_name( "Add a lot of numbers through a vector" );
	{
		std::vector<int>	vec = { -10, INT_MIN, 4, 42, 1234, INT_MAX };

		try
		{
			Span	s( vec.size() );

			s.print();
			s.addABunchOfNumbers< std::vector<int> >( vec.begin(), vec.end() );
			s.print();
			std::cout << s.shortestSpan() << std::endl;
			std::cout << s.longestSpan() << std::endl;
		}
		catch ( std::exception const &e )
		{
			std::cout << e.what() << '\n';
		}
	}
	print_test_name( "Add a lot of numbers through a deque" );
	{
		std::deque<int>	dq = { -10, INT_MIN, 4, 42, 1234, INT_MAX };

		try
		{
			Span	s( dq.size() );

			s.print();
			s.addABunchOfNumbers< std::deque<int> >( dq.begin(), dq.end() );
			s.print();
			std::cout << s.shortestSpan() << std::endl;
			std::cout << s.longestSpan() << std::endl;
		}
		catch ( std::exception const &e )
		{
			std::cout << e.what() << '\n';
		}
	}
	print_test_name( "Add a lot of numbers through an array" );
	{
		std::array<int, 6>	arr = { -10, INT_MIN, 4, 42, 1234, INT_MAX };

		try
		{
			Span	s( arr.size() );

			s.print();
			s.addABunchOfNumbers< std::array<int, 6> >( arr.begin(), arr.end() );
			s.print();
			std::cout << s.shortestSpan() << std::endl;
			std::cout << s.longestSpan() << std::endl;
		}
		catch ( std::exception const &e )
		{
			std::cout << e.what() << '\n';
		}
	}
	print_test_name( XSTR(BIG_NUMBER) " random numbers" );
	{
		std::vector<int>					vec;
		std::random_device					rd;
		std::mt19937						generator( rd() );
		std::uniform_int_distribution<int>	dist( INT_MIN, INT_MAX );

		for ( size_t i = 0; i < BIG_NUMBER; ++i )
			vec.push_back( dist( generator ) );

		try
		{
			Span	s( vec.size() );

			s.addABunchOfNumbers< std::vector<int> >( vec.begin(), vec.end() );
			std::cout << s.shortestSpan() << std::endl;
			std::cout << s.longestSpan() << std::endl;
		}
		catch ( std::exception const &e )
		{
			std::cout << e.what() << '\n';
		}
	}
	std::cout << std::endl;
}

static void			subjectsMain()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

/* -------------------------------------------------------------------------- */

static void print_test_name( std::string str )
{
	for ( size_t i = 0; i < str.size(); ++i )
		str[i] = std::toupper( str[i] );

	size_t width = str.length() + 10;

	std::string separator = n_chars( '-', width );
	std::cout << "\n" C_HI_Y << separator << '\n';
	std::cout << "**** " << str << " ****";
	std::cout << '\n' << separator << C_RST "\n";
	std::cout << std::endl;
}

static std::string n_chars( char c, size_t n )
{
	std::string str = "";
	while ( n-- )
		str += c;
	return str;
}
