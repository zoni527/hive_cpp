/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:04:01 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/02 16:09:16 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
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

int main()
{
	{
		print_test_name("Human A test");
		Weapon club = Weapon("crude spiked club");
		HumanA human_a(random_name(), club);
		human_a.attack();
		club.setType("some other type of club");
		human_a.attack();
	}
	{
		print_test_name("Human B test");
		Weapon club = Weapon("crude spiked club");
		HumanB human_b(random_name());
		human_b.attack();
		human_b.setWeapon(club);
		human_b.attack();
		club.setType("some other type of club");
		human_b.attack();
	}
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
