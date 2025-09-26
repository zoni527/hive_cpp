/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:46:37 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:12:45 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "ansi_colors.hpp"
#include <iostream>

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );

int main() {

	print_test_name( "ex00 main (meta animal commented out)" );
	{
		// const AAnimal* meta = new Animal();
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		std::cout << "\n";
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << "\n";
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		// meta->makeSound();
		std::cout << "\n";
		// delete meta;
		delete j;
		delete i;
	}
	print_test_name( "array of animals" );
	{
		unsigned const num_of_animals = 8;
		AAnimal const *animal_array[ num_of_animals ];
		for ( unsigned int i = 0; i < num_of_animals; ++i ) {
			if ( i < num_of_animals / 2 )
				animal_array[i] = new Dog();
			else
				animal_array[i] = new Cat();
		}
		std::cout << "\n";
		for ( AAnimal const *a : animal_array ) {
			std::cout << C_B_HI_W "AAnimal" C_RST "	type: " << a->getType() << "\n";
			a->makeSound();
			delete a;
			a = nullptr;
		}
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
