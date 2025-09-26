/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:46:37 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:13:23 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "ansi_colors.hpp"
#include <iostream>

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );

int main() {

	srand( time( NULL ));
	print_test_name( "subject's main (with better formatting)" );
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "\n";
		delete j;//should not create a leak
		delete i;
	}
	print_test_name( "array of animals" );
	{
		unsigned const num_of_animals = 8;
		Animal const *animal_array[ num_of_animals ];
		for ( unsigned int i = 0; i < num_of_animals; ++i ) {
			if ( i < num_of_animals / 2 )
				animal_array[i] = new Dog();
			else
				animal_array[i] = new Cat();
		}
		std::cout << "\n";
		for ( Animal const *a : animal_array ) {
			a->makeSound();
			delete a;
			a = nullptr;
		}
	}
	print_test_name("is the copy constructor a shallow copy?");
	{
		Dog	one;
		std::cout << "\n";
		for ( size_t i = 0; i < 10; ++i )
			std::cout << one.get_idea( i ) << "\n";
		std::cout << "\n";
		{
			Dog	two( one );
			std::cout << "\n";
			for ( size_t i = 0; i < 10; ++i )
				std::cout << two.get_idea( i ) << "\n";
			std::cout << "\n";
		}
		std::cout << "\n";
		for ( size_t i = 0; i < 10; ++i )
			std::cout << one.get_idea( i ) << "\n";
		std::cout << "\n";
	}
	print_test_name("is the copy assignment operator a shallow copy?");
	{
		Dog	one;
		std::cout << "\n";
		for ( size_t i = 0; i < 10; ++i )
			std::cout << one.get_idea( i ) << "\n";
		std::cout << "\n";
		{
			Dog	two;
			std::cout << "\n";
			for ( size_t i = 0; i < 10; ++i )
				std::cout << two.get_idea( i ) << "\n";
			std::cout << "\n";
			two = one;
			std::cout << "\n";
			for ( size_t i = 0; i < 10; ++i )
				std::cout << one.get_idea( i ) << "\n";
			std::cout << "\n";
		}
		std::cout << "\n";
		for ( size_t i = 0; i < 10; ++i )
			std::cout << one.get_idea( i ) << "\n";
		std::cout << "\n";
	}
	std::cout << std::endl;
	return 0;
}

// ------------------------------------------------------------ static functions

static void print_test_name( std::string str ) {

	for ( char &c : str )
		c = std::toupper( c );

	size_t width = str.length() + 10;

	std::string separator = n_chars( '-', width );
	std::cout << "\n" C_HI_Y << separator << "\n";
	std::cout << "**** " << str << " ****";
	std::cout << "\n" << separator << C_RST "\n";
	std::cout << std::endl;
}

static std::string n_chars( char c, size_t n ) {
	std::string str = "";
	while ( n-- )
		str += c;
	return str;
}
