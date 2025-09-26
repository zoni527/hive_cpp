/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:24:22 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/02 16:09:41 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

#define YELLOW	"\033[0;93m\001"
#define RESET	"\033[0m\002"

static void			harl_filter( std::string str );
static void			print_level_header( int i );
static void			tests();
static void			test(	std::string const &test_name,
							std::string const &input);
static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );

std::string const levels[] = {
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR",
};

int main( int argc, char *argv[] ) {

	if (argc != 2) { std::cerr << "Usage: ./harl_filter <input string>" << std::endl;
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
	harl_filter(argv[1]);
	return 0;
}

static void harl_filter( std::string str ) {

	int i;
	for (i = 0; i < 4; ++i)
		if (levels[i] == str)
			break;

	Harl harl;
	// Without a break the switch statement will execute all following cases
	// after the match.
	switch (i) {
		case 0:
			print_level_header(i);
			harl.complain(levels[i++]);
			std::cout << "\n";
		case 1:
			print_level_header(i);
			harl.complain(levels[i++]);
			std::cout << "\n";
		case 2:
			print_level_header(i);
			harl.complain(levels[i++]);
			std::cout << "\n";
		case 3:
			print_level_header(i);
			harl.complain(levels[i]);
			std::cout << "\n";
			break;
		case 4:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

static void print_level_header( int i ) {
	std::string level = levels[i];
	for (char &c : level)
		c = std::toupper(c);
	std::cout << "[ " << level << " ]\n";
	
}

static void tests() {

	test("Test 1: debug", "DEBUG");
	test("Test 2: info", "INFO");
	test("Test 3: warning", "WARNING");
	test("Test 4: error", "ERROR");
	test("Test 5: something_else", "SOMETHING_ELSE");
	test("Test 6: empty string", "");
}

static void test(	std::string const &test_name,
							std::string const &input) {
	print_test_name(test_name);
	std::cout << "harl_filter(" << input << ") -> \n\n";
	harl_filter(input);
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

	size_t width = str.length() + 10;

	std::string separator = n_chars('-', width);
	std::cout << "\n" YELLOW << separator << "\n";
	std::cout << "**** " << str << " ****";
	std::cout << "\n" << separator << RESET "\n";
	std::cout << std::endl;
}
