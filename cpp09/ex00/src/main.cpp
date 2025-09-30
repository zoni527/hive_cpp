/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:40:48 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/30 17:57:34 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

#define C_HI_Y	"\033[0;93m\001"
#define C_RST	"\033[0m\002"

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );

int	main( int argc, char *argv[] )
{
	if ( argc != 2)
	{
		std::cout << "Usage: ./btc <input_file_name>" << std::endl;
		return 1;
	}
	(void)print_test_name;
	BitcoinExchange	b( argv[1] );
	b.run();
	return 0;
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
