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

int	main( int argc, char *argv[] )
{
	if ( argc != 2)
	{
		std::cout << "Usage: ./btc <input_file_name>" << std::endl;
		return 1;
	}
	BitcoinExchange	b( argv[1] );
	b.run();
	return 0;
}
