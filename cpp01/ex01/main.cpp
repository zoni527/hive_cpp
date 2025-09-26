/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:11:24 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/02 16:08:24 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

static std::string const random_names[] = {
	"Mark",
	"Ross",
	"Greg",
	"Roni",
	"Aino",
	"Noe",
	"Colin",
	"Laura",
	"Yutong",
	"Batman",
	"Mario",
	"Luigi",
	"Salla",
	"Matias",
};

static std::string const	&random_name();
static std::string			n_chars( char c, size_t n );
static void					print_test_name( std::string str );

int main( int argc, char *argv[] ) {

	srand(time(NULL));

	size_t n = 10;
	if (argc != 1) {
		try {
			n = std::stoi(argv[1]);
			if (n <= 0) {
				std::cout << "Bad amount, using default (10)\n";
				n = 10;
			}
		}
		catch (...) {}
	}
	print_test_name("Zombie horde test");
	std::string name = random_name();
	try {
		Zombie *horde = zombieHorde(n, name);
		for (size_t i = 0; i < n; ++i)
			horde[i].announce();
		delete[] horde;
	}
	catch (std::bad_alloc&) {
		std::cerr << "ERROR: bad allocation" << std::endl;
	}
	return 0;
}

// -----------------------------------------------------------------------------

static std::string const &random_name() {
	size_t n_names = sizeof(random_names) / sizeof(random_names[0]);
	return (random_names[rand() % n_names]);
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
	std::cout << "\n" << separator << "\n";
	std::cout << "**** " << str << " ****";
	std::cout << "\n" << separator << "\n";
	std::cout << std::endl;
}
