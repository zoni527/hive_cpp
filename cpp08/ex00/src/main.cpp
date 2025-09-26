/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:40:48 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/16 16:07:58 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <array>

#define C_HI_Y	"\033[0;93m\001"
#define C_RST	"\033[0m\002"

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );

int	main()
{
	print_test_name( "Vector test" );
	{
		std::vector<int>	vec = { -1, 0, 1, 2, 3, 42, 50 };

		try
		{
			int	num = 42;
			std::cout << "Looking for number:	" << num << '\n';
			int	found = *easyfind< std::vector<int> >( vec, num );
			std::cout << "Found number:		" << found << '\n';

			num = 420;
			std::cout << "Looking for number:	" << num << '\n';
			found = *easyfind< std::vector<int> >( vec, num );
			std::cout << "Found number:		" << found << '\n';
		}
		catch ( std::exception const &e )
		{
			std::cout << e.what() << '\n';
		}
	}
	print_test_name( "Deque test" );
	{
		std::deque<int>	dq = { -1, 0, 1, 2, 3, 42, 50 };

		try
		{
			int	num = 42;
			std::cout << "Looking for number:	" << num << '\n';
			int	found = *easyfind< std::deque<int> >( dq, num );
			std::cout << "Found number:		" << found << '\n';

			num = 420;
			std::cout << "Looking for number:	" << num << '\n';
			found = *easyfind< std::deque<int> >( dq, num );
			std::cout << "Found number:		" << found << '\n';
		}
		catch ( std::exception const &e )
		{
			std::cout << e.what() << '\n';
		}
	}
	print_test_name( "Array" );
	{
		std::array<int, 7>	dq = { -1, 0, 1, 2, 3, 42, 50 };

		try
		{
			int	num = 42;
			std::cout << "Looking for number:	" << num << '\n';
			int	found = *easyfind< std::array<int, 7> >( dq, num );
			std::cout << "Found number:		" << found << '\n';

			num = 420;
			std::cout << "Looking for number:	" << num << '\n';
			found = *easyfind< std::array<int, 7> >( dq, num );
			std::cout << "Found number:		" << found << '\n';
		}
		catch ( std::exception const &e )
		{
			std::cout << e.what() << '\n';
		}
	}
	std::cout << std::endl;
}

/* -------------------------------------------------------------------------- */

static void print_test_name( std::string str )
{
	for ( size_t i = 0; i < str.size(); ++i )
		str[i] = std::toupper( str[i] );

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
