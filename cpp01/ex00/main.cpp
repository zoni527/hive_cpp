/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:11:24 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/02 16:08:28 by jvarila          ###   ########.fr       */
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

int main() {

	srand(time(NULL));

	// Brackets create a separate scope. The destructor gets called when the end
	// of the scope of the variable is reached, which is the closing bracket.
	print_test_name("Stack zombie test");
	{
		Zombie stack_zombie(random_name());
		stack_zombie.announce();
	}
	// When there is a heap zombie it is important to free the pointer before we
	// reach the end of its scope.
	print_test_name("Heap zombie test");
	try {
		Zombie *heap_zombie = newZombie(random_name());
		heap_zombie->announce();
		delete heap_zombie;
	}
	catch (std::bad_alloc&) {
		std::cerr << "ERROR: failed to allocate memory" << std::endl;
	}
	// The random zombie created when calling randomChump only exists within the
	// function's scope, so it gets deleted after the function completes.
	print_test_name("Random chump test");
	randomChump(random_name());
	std::cout << std::endl;
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
