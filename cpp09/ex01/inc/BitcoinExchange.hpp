/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:21:07 by jvarila           #+#    #+#             */
/*   Updated: 2025/10/03 12:25:27 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>

class BitcoinExchange
{
public:
	BitcoinExchange() = delete;
	BitcoinExchange( BitcoinExchange const &other ) = delete;
	BitcoinExchange(	std::string const &inputFileName,
						std::string const &dataFileName = "data.csv");
	~BitcoinExchange() = default;

	BitcoinExchange	&operator=( BitcoinExchange const &rhs ) = delete;

	void	run();

private:
	std::string const				_dataFileName;
	std::string const				_inputFileName;
	std::map< std::string, float >	_data;

	bool	dataParseSuccessful();
	bool	inputParseSuccessful();
};
