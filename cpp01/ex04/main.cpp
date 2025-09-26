/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:49:20 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/02 16:09:20 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "SedIsForLosers.hpp"
#include "fstream"

#define GREEN	"\033[0;32m\001"
#define RED		"\033[0;31m\001"
#define YELLOW	"\033[0;93m\001"
#define RESET	"\033[0m\002"

static void			tests();
static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );
static void			print_file( std::string const &file_name );
static void			test(	std::string const &test_name,
							std::string const &file,
							std::string const &s1,
							std::string const &s2);

int main( int argc, char *argv[] ) {

	if (argc != 4) {
		std::cout << "\nUsage: ./sed_is_for_losers <filename> <s1> <s2>\n";

		std::cout << "\nDo you want to run the default test suite? (y/n) > " << std::flush;
		std::string input;
		std::getline(std::cin, input);
		for (char &c : input)
			c = std::tolower(c);
		if (input == "y" || input == "yes")
			tests();

		std::cout << std::endl;
		return 0;
	}

	SedIsForLosers obj(argv[1], argv[2], argv[3]);
	obj.run();
	return 0;
}

static void tests() {

	test("Test 1: valid input", "Makefile", "OBJ", "----> REPLACED <----");
	test("Test 2: replace with empty string (s2 = \"\")", "SedIsForLosers.hpp", " ", "");
	test("Test 3: s1 = \"\"", "SedIsForLosers.hpp", "", "a");
	test("Test 4: replace new lines", "SedIsForLosers.hpp", "\n", RED "THERE_USED_TO_BE_A_NEWLINE_HERE" RESET);
	test("Test 5: invalid file", "no_such_file", "one", "two");
	test("Test 6: all empty strings", "", "", "");
}

static std::string n_chars( char c, size_t n ) {
	std::string str = "";
	while (n--)
		str += c;
	return str;
}

static void print_test_name( std::string str ) {

	for (char &c : str)
		c = std::toupper(c);

	auto width = str.length() + 10;

	std::string separator = n_chars('-', width);
	std::cout << "\n" YELLOW << separator << "\n";
	std::cout << "**** " << str << " ****";
	std::cout << "\n" << separator << RESET "\n";
	std::cout << std::endl;
}

static void print_file( std::string const &file_name ) {

	std::ifstream	infile(file_name);
	std::string		line;
	while (std::getline(infile, line)) {
		std::cout << line << "\n";
	}
}

static void			test(	std::string const &test_name,
							std::string const &file,
							std::string const &s1,
							std::string const &s2) {

	print_test_name(test_name);
	std::cout << "file:	\"" << file << "\"\n";
	std::cout << "s1:	\"" << s1 << "\"\n";
	std::cout << "s2:	\"" << s2 << "\"\n\n";
	SedIsForLosers obj(file, s1, s2);
	if (obj.run() == 0) {
		print_file(file + ".replace");
		std::cout << GREEN "\n*** PROGRAM RAN SUCCESSFULLY! ***" RESET << std::endl;
	}
}
