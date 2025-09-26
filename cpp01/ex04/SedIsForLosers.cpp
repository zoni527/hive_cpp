/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedIsForLosers.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:40:49 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/02 16:09:18 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"
#include <string>
#include <iostream>
#include <fstream>

// ------------------------------------------------------------ member functions

int SedIsForLosers:: run() {

	if (_s1.empty()) {
		std::cerr << "ERROR: can't replace empty string" << std::endl;
		return 1;
	}

	std::ifstream infile(_file);
	if (!infile) {
		std::cerr << "ERROR: couldn't open file: " << _file << std::endl;
		return 1;
	}

	std::ofstream outfile(_file + ".replace");
	if (!outfile) {
		std::cerr << "ERROR: couldn't open file: " << _file + ".replace" << std::endl;
		return 1;
	}

	std::string line = "";
	while (std::getline(infile, line)) {
		size_t word_index = 0;
		if (!infile.eof())
			line += "\n";
		while ((word_index = line.find(_s1, word_index)) != std::string::npos) {
			line.erase(word_index, _s1.size());
			line.insert(word_index, _s2);
			word_index += _s2.length();
		}
		outfile << line;
	}
	return 0;
}

// ----------------------------------------------------------------- constructor

SedIsForLosers:: SedIsForLosers(	std::string const &file,
									std::string const &s1,
									std::string const &s2 ) :
	_file(file), _s1(s1), _s2(s2) {}
