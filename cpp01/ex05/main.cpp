/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:24:22 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/02 16:09:37 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

#define GREEN	"\033[0;32m\001"
#define RED		"\033[0;31m\001"
#define YELLOW	"\033[0;93m\001"
#define RESET	"\033[0m\002"

static void			tests();
static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );
static void			test(	std::string const &test_name,
							std::string const &input);

int main() {
	tests();
	return 0;
}

static void tests() {

	test("Test 1: debug", "DEBUG");
	test("Test 2: info", "INFO");
	test("Test 3: warning", "WARNING");
	test("Test 4: error", "ERROR");
	test("Test 5: something_else", "SOMETHING_ELSE");
	test("Test 6: empty string", "");
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

static void			test(	std::string const &test_name,
							std::string const &input) {

	print_test_name(test_name);

	Harl harl;
	harl.complain(input);
}
