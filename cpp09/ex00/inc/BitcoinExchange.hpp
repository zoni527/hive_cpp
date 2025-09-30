/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:21:07 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/30 17:50:17 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class BitcoinExchange
{
public:
	BitcoinExchange() = delete;
	BitcoinExchange( BitcoinExchange const &other ) = delete;
	BitcoinExchange(	std::string const &inputFileName,
						std::string const &dataFileName = "data.csv");
	~BitcoinExchange() = default;

	BitcoinExchange	&operator=( BitcoinExchange const &rhs ) = delete;

	void	run()				const;
	void	printDataFile()		const;
	void	printInputFile()	const;
private:
	std::string const _dataFileName;
	std::string const _inputFileName;
};
