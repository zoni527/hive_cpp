/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:11:02 by jvarila           #+#    #+#             */
/*   Updated: 2025/10/03 17:36:47 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <regex>
#include <chrono>
#include <iomanip>

/* -------------------------------------------------------------------------- */

#define	RED	"\033[1;31m\001"
#define	RHL	"\033[1;91m\001"
#define WHL	"\033[1;97m\001"
#define RST	"\033[0m\002"

/* -------------------------------------------------------------------------- */

static bool	lineMatchesFormat(	std::string const	&line,
								std::smatch			&match,
								std::regex const	&reg,
								size_t				lineCounter,
								std::string const	&fileType );

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
			<< RED "Error:" RST " Couldn't open database file "
			<< RHL << _dataFileName << RST << std::endl;
		return false;
	}

	auto		streamStart = dataFile.tellg(); // Save file start position
	std::string	line;

	std::getline( dataFile, line );
	if ( line.empty() && !dataFile ) // Check for empty file (a single newline also counts)
	{
		std::cout
			<< RED "Error:" RST " Empty data file" << std::endl;
		return false;
	}
	dataFile.seekg( streamStart ); // Restore stream to start of file

	// Regex matches the date format exactly, no allowed whitespace
	// For numbers either an int or a float with both a whole and fractional part
	// I'm allowing negative values for fun, I like the idea of somebody paying
	// you to own bitcoin
	std::regex	reg( R"(((^\d{4})-(\d{2})-(\d{2})),([+-]?\d+(\.\d+)?)$)" );
	std::smatch	match;
	size_t		lineCounter = 0;

	while ( std::getline( dataFile, line ) )
	{
		++lineCounter;

		// First line might be a header
		if ( lineCounter == 1 && !std::regex_match( line, match, reg ) )
			continue;

		if ( !lineMatchesFormat( line, match, reg, lineCounter, "Data file" ) )
			continue;

		if ( !dateIsValid( match, "Data file", lineCounter ) )
			continue;

		if ( !bitcoinValueOverflows( match, "Data file", lineCounter ) )
			_data[ match[1] ] = std::stof( match[5] );
	}
	
	return true;
}

bool	BitcoinExchange:: inputParseSuccessful()
{
	std::ifstream	inputFile( _inputFileName );
	if ( !inputFile )
	{
		std::cout
			<< RED "Error:" RST " Couldn't open input file "
			<< RHL << _inputFileName << RST << std::endl;
		return false;
	}

	std::string	line;

	auto	streamStart = inputFile.tellg();

	std::getline( inputFile, line );
	if ( line.empty() && !inputFile )
	{
		std::cout
			<< RED "Error:" RST " Empty input file." << std::endl;
		return false;
	}
	inputFile.seekg( streamStart );

	std::regex	reg( R"(\s*((\d{4})-(\d{2})-(\d{2}))\s*\|\s*([+-]?\d+(\.\d+)?)\s*$)" );
	std::smatch	match;
	size_t		lineCounter = 0;

	while ( std::getline( inputFile, line ))
	{
		++lineCounter;

		if ( lineCounter == 1 && !std::regex_match( line, match, reg ) )
			continue;

		if ( !lineMatchesFormat(	line, match, reg, lineCounter, "Input file" ) )
			continue;

		if ( !dateIsValid( match, "Input file", lineCounter ) )
			continue;

		if ( bitcoinValueOverflows( match, "Input file", lineCounter ) )
			continue;

		float	value = std::stof( match[5] );

		if ( value < 0 )
		{
			std::cout
				<< RED "Error:" RST " Input file: line " << lineCounter
				<<	": number " << RHL << match[5] << RST << " is not positive.\n";
			continue;
		}

		if ( value > 1000 )
		{
			std::cout
				<< RED "Error:" RST " Input file: line " << lineCounter
				<<	": number " << RHL << match[5] << RST << " is over 1000.\n";
			continue;
		}

		std::string	closestDate = std::string( 10, 0 );
		
		for ( auto &d : _data )
		{
			if ( d.first < match[1] && d.first > closestDate )
				closestDate = d.first;
			if ( closestDate == match[1] )
				break;
		}

		std::setprecision( 15 );

		if ( closestDate[0] != 0 )
		{
			float	bitcoinValue = _data[closestDate];

			std::cout
				<< match[1] << " | " << std::left << std::setw( 6 ) << value
				<< " => " << closestDate << ", " << std::setw( 6 ) << bitcoinValue
				<< " => "  << std::right << std::setw( 6 ) << value << " * "
				<< std::left << std::setw( 6 ) << bitcoinValue
				<< " = " WHL << value * bitcoinValue << RST
				<< "\n";
		}
		else
		{
			std::cout
				<< RED "Error:" RST " Input file: line " << lineCounter
				<<	": no matching or earlier date in database.\n";
		}
	}

	return true;
}

/* -------------------------------------------------------------------------- */

static bool	lineMatchesFormat(	std::string const	&line,
								std::smatch			&match,
								std::regex const	&reg,
								size_t				lineCounter,
								std::string const	&fileType )
{
	if ( !std::regex_match( line, match, reg ) )
	{
		std::cout
			<< RED "Error:" RST " " << fileType << ": line " << lineCounter
			<<	": bad input: " << RHL << line << RST << std::endl;
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
			<< RED "Error:" RST " " << fileType << ": line " << lineCounter
			<< ": date " << RHL << match[1] << RST
			<< " is invalid.\n";
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
		std::stof( match[5] );
	}
	catch ( std::exception const &e )
	{
		std::cout
			<< RED "Error:" RST " " << fileType << ": line " << lineCounter
			<< ": bitcoin value " << RHL << match[5] << RST
			<< " is invalid.\n";
		return true;
	}
	return false;
}
