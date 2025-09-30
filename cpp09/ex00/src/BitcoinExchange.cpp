/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:11:02 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/30 17:54:17 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

BitcoinExchange:: BitcoinExchange(	std::string const &inputFileName ,
									std::string const &dataFileName )
	:	_dataFileName( dataFileName ),
		_inputFileName( inputFileName ) {}

void	BitcoinExchange:: run() const
{
	printDataFile();
}

void	BitcoinExchange:: printDataFile() const
{
	std::ifstream	dataFile( _dataFileName );
	if ( !dataFile )
	{
		std::cout
			<< "ERROR: BitcoinExchange: run: "
			<< "couldn't open database file: "
			<< _dataFileName << std::endl;
		return;
	}
	std::string	line;
	while ( std::getline( dataFile, line))
		std::cout << line << '\n';
	std::cout << std::endl;
}

void	BitcoinExchange:: printInputFile() const
{
	std::ifstream	inputFile( _inputFileName );
	if ( !inputFile )
	{
		std::cout
			<< "ERROR: BitcoinExchange: run: "
			<< "couldn't open input file: "
			<< _dataFileName << std::endl;
		return;
	}
}
