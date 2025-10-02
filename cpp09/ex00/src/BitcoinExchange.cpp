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
#include <regex>
#include <chrono>

/* -------------------------------------------------------------------------- */

static bool	lineMatchesFormat(	std::string const	&line,
								std::smatch			&match,
								std::regex const	&reg,
								size_t				lineCounter,
								std::string const	&fileType,
								std::string const	&format );

static bool	dateIsValid(	std::smatch const	&match,
							std::string const	&fileType,
							size_t				lineCounter );

static bool	bitcoinValueOverflows(	std::smatch const	&match,
									std::string const	&fileType,
									size_t				lineCounter );

/* -------------------------------------------------------------------------- */

BitcoinExchange:: BitcoinExchange(	std::string const &inputFileName ,
									std::string const &dataFileName )
	:	_dataFileName( dataFileName ),
		_inputFileName( inputFileName ) {}

/* -------------------------------------------------------------------------- */

void	BitcoinExchange:: run()
{
	dataParseSuccessful();
	inputParseSuccessful();
}

bool	BitcoinExchange:: dataParseSuccessful()
{
	std::ifstream	dataFile( _dataFileName );

	if ( !dataFile )
	{
		std::cout
			<< "Error: Couldn't open database file `"
			<< _dataFileName << "'" << std::endl;
		return false;
	}

	// Regex matches the date format exactly, no allowed whitespace
	// For numbers either an int or a float with both a whole and fractional part
	// I'm allowing negative values for fun, I like the idea of somebody paying
	// you to own bitcoin
	std::regex	reg( R"(((^\d{4})-(\d{2})-(\d{2})),([+-]?\d+(\.\d+)?)$)" );
	std::smatch	match;
	std::string	line;

	// Check for empty file
	auto	streamStart = dataFile.tellg();

	std::getline( dataFile, line );
	if ( line.empty() && !dataFile )
	{
		std::cout
			<< "Error: Empty data file" << std::endl;
		return false;
	}
	dataFile.seekg( streamStart ); // Restore stream

	std::map< std::string, double >	data;
	size_t							lineCounter = 0;

	while ( std::getline( dataFile, line ) )
	{
		++lineCounter;

		// First line might be a header
		if ( lineCounter == 1 && !std::regex_match( line, match, reg ) )
			continue;

		if ( !lineMatchesFormat(	line, match, reg, lineCounter,
									"Data file",
									"(yyyy-mm-dd,<whole part>[.fractional part])" ) )
			continue;

		if ( !dateIsValid( match, "Data file", lineCounter ) )
			continue;

		if ( !bitcoinValueOverflows( match, "Data file", lineCounter ) )
			data[ match[1] ] = std::stod( match[5] );
	}
	
	return true;
}

bool	BitcoinExchange:: inputParseSuccessful()
{
	std::ifstream	inputFile( _inputFileName );
	if ( !inputFile )
	{
		std::cout
			<< "Error: Couldn't open input file `"
			<< _inputFileName << "'" << std::endl;
		return false;
	}

	std::regex	reg( R"(\s*((\d{4})-(\d{2})-(\d{2}))\s*\|\s*([+-]?\d+(\.\d+)?)\s*$)" );
	std::smatch	match;
	std::string	line;

	auto	streamStart = inputFile.tellg();

	std::getline( inputFile, line );
	if ( line.empty() && !inputFile )
	{
		std::cout
			<< "Error: Empty input file" << std::endl;
		return false;
	}
	inputFile.seekg( streamStart );

	size_t	lineCounter = 1;
	while ( std::getline( inputFile, line ))
	{
		++lineCounter;

		if ( lineCounter == 1 && !std::regex_match( line, match, reg ) )
			continue;

		if ( !lineMatchesFormat(	line, match, reg, lineCounter,
									"Input file",
									"(yyyy-mm-dd | <whole part>[.fractional part])" ) )
			continue;

		if ( !dateIsValid( match, "Input file", lineCounter ) )
			continue;

		if ( bitcoinValueOverflows( match, "Input file", lineCounter ) )
			continue;
	}

	return true;
}

/* -------------------------------------------------------------------------- */

static bool	lineMatchesFormat(	std::string const	&line,
								std::smatch			&match,
								std::regex const	&reg,
								size_t				lineCounter,
								std::string const	&fileType,
								std::string const	&format )
{
	if ( !std::regex_match( line, match, reg ) )
	{
		std::cout
			<< "Error: "<< fileType << ": line " << lineCounter
			<<	": doesn't match required format "
			<< format << std::endl;
		return false;
	}
	return true;
}

static bool	dateIsValid(	std::smatch const	&match,
							std::string const	&fileType,
							size_t				lineCounter )
{
	int	year	= std::stoi( match[2] );
	int	month	= std::stoi( match[3] );
	int	day		= std::stoi( match[4] );
	std::chrono::year_month_day	ymd(	static_cast<std::chrono::year>( year ),
										static_cast<std::chrono::month>( month ),
										static_cast<std::chrono::day>( day ) );
	if ( !ymd.ok() )
	{
		std::cout
			<< "Error: " << fileType << ": line " << lineCounter
			<< ": date `" << match[1] << "' is invalid\n";
		return false;
	}
	return true;
}

static bool	bitcoinValueOverflows(	std::smatch const	&match,
									std::string const	&fileType,
									size_t				lineCounter )
{
	try
	{
		std::stod( match[5] );
	}
	catch ( std::exception const &e )
	{
		std::cout
			<< "Error: " << fileType << ": line " << lineCounter
			<< ": bitcoin value `" << match[5] << "' is invalid\n";
		return true;
	}
	return false;
}
