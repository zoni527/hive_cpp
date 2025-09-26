/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:46:37 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:15:32 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"
#include "ansi_colors.hpp"
#include <iostream>

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );

int main() {

	print_test_name( "subject's main (with better formatting)" );
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "\n";

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << "\n";

		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		std::cout << "\n";

		delete meta;
		delete i;
		delete j;
	}
	print_test_name( "subject's main with wrong animals (with better formatting)" );
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* j = new WrongDog();
		const WrongAnimal* i = new WrongCat();
		std::cout << "\n";

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << "\n";

		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		std::cout << "\n";

		delete meta;
		delete i;
		delete j;
	}
	print_test_name( "default costructors" );
	{
		{
			Animal	a;
			std::cout << "\n";
			Dog		d;
			std::cout << "\n";
			Cat		c;
			std::cout << "\n";
		}
		std::cout << std::endl;
		{
			WrongAnimal	a;
			std::cout << "\n";
			WrongDog	d;
			std::cout << "\n";
			WrongCat	c;
			std::cout << "\n";
		}
	}
	print_test_name( "copy constructors" );
	{
		{
			Animal	a1;
			Animal	a2( a1 );
			std::cout << "\n";
			Dog		d1;
			Dog		d2( d1 );
			std::cout << "\n";
			Cat		c1;
			Cat		c2( c1 );
			std::cout << "\n";
		}
		std::cout << std::endl;
		{
			WrongAnimal	a1;
			WrongAnimal	a2( a1 );
			std::cout << "\n";
			WrongDog		d1;
			WrongDog		d2( d1 );
			std::cout << "\n";
			WrongCat		c1;
			WrongCat		c2( c1 );
			std::cout << "\n";
		}
	}
	print_test_name( "copy assignment operators" );
	{
		{
			Animal	a1, a2;
			a1 = a2;
			std::cout << "\n";
			Dog		d1, d2;
			d1 = d2;
			std::cout << "\n";
			Cat		c1, c2;
			c1 = c2;
			std::cout << "\n";
		}
		std::cout << std::endl;
		{
			WrongAnimal	a1, a2;
			a1 = a2;
			std::cout << "\n";
			WrongDog		d1, d2;
			d1 = d2;
			std::cout << "\n";
			WrongCat		c1, c2;
			c1 = c2;
			std::cout << "\n";
		}
	}
	print_test_name( "makeSound()" );
	{
		{
			Animal().makeSound();
			std::cout << "\n";
			Dog().makeSound();
			std::cout << "\n";
			Cat().makeSound();
		}
		std::cout << std::endl;
		{
			WrongAnimal().makeSound();
			std::cout << "\n";
			WrongDog().makeSound();
			std::cout << "\n";
			WrongCat().makeSound();
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
