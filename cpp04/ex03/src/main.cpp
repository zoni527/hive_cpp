/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:58:17 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:14:36 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ansi_colors.hpp"
#include <iostream>

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );

extern AMateria		*floor[ N_FLOOR ];

int main() {

	print_test_name( "Subject's main with better formatting" );
	{
		IMateriaSource* src = new MateriaSource();
		std::cout << "\n";
		src->learnMateria(new Ice());
		std::cout << "\n";
		src->learnMateria(new Cure());
		std::cout << "\n";

		ICharacter* me = new Character("me");
		std::cout << "\n";

		AMateria* tmp;
		tmp = src->createMateria("ice");
		std::cout << "\n";
		me->equip(tmp);
		std::cout << "\n";
		tmp = src->createMateria("cure");
		std::cout << "\n";
		me->equip(tmp);
		std::cout << "\n";

		ICharacter* bob = new Character("bob");
		std::cout << "\n";

		me->use(0, *bob);
		std::cout << "\n";
		me->use(1, *bob);
		std::cout << "\n";

		delete bob;
		delete me;
		delete src;
	}
	print_test_name( "Equip" );
	{
		Character me( "me" );
		std::cout << "\n";
		me.equip( new Ice() );
		std::cout << "\n";
		me.equip( new Cure() );
		std::cout << "\n";
		me.equip( nullptr );
		std::cout << "\n";
		me.equip( new Cure() );
		std::cout << "\n";
		me.equip( new Cure() );
		std::cout << "\n";
		me.equip( new Cure() );
		std::cout << "\n";
	}
	print_test_name( "Unequip" );
	{
		Character me( "me" );
		std::cout << "\n";
		me.equip( new Ice() );
		std::cout << "\n";
		me.equip( new Cure() );
		std::cout << "\n";
		me.unequip( 0 );
		std::cout << "\n";
		me.unequip( 2 );
		std::cout << "\n";
		me.unequip( 10 );
		std::cout << "\n";
		me.unequip( 1 );
		std::cout << "\n";
	}
	for ( AMateria *ptr : floor ) {
		if ( ptr )
			std::cout << ptr->getType() << std::endl;
		delete ptr;
	}
	std::cout << "\n";
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
