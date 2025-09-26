/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:51:00 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:14:09 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "ansi_colors.hpp"
#include <cstdlib>
#include <iostream>

// -----------------------------------------------------------------------------

std::string const	random_ideas[] = {
	"\"I am hungry\"",
	"\"I am thirsty\"",
	"\"I am horny\"",
	"\"SQUIRREL!\"",
	"\"I hate my owner...\"",
	"\"I love my owner!\"",
	"\":(\"",
	"\":)\"",
	"\"I wonder if I could break that vase...\"",
	"\"Lick lick\"",
	"\"Derp\"",
	"\"Herp\"",
	"\"This would be an excellent opportunity to escape...\"",
};

std::string const	id_str = C_B_HI_Y "Brain" C_RST;

// -----------------------------------------------------------------------------

std::string Brain:: get_idea( size_t index ) {

	if ( index >= N_IDEAS )
		return "Error! Invalid index";
	return _ideas[index];
}

std::string Brain:: get_random_idea() {

	size_t number_of_random_ideas = sizeof( random_ideas ) / sizeof( random_ideas[0] );
	size_t random_index = rand() % number_of_random_ideas;
	return _ideas[ random_index ];
}

// -----------------------------------------------------------------------------

Brain:: Brain() {

	std::cout << id_str + "	Default constructor called" << std::endl;

	size_t number_of_random_ideas = sizeof( random_ideas ) / sizeof( random_ideas[0] );
	for ( int i = 0; i < N_IDEAS; ++i )
		_ideas[i] = random_ideas[ rand() % number_of_random_ideas ];
}

Brain:: Brain( Brain const &src ) {

	std::cout << id_str + "	Copy constructor called" << std::endl;

	if ( this != &src )
		for ( int i = 0; i < N_IDEAS; ++i )
			_ideas[i] = src._ideas[i];
}

// -----------------------------------------------------------------------------

Brain:: ~Brain() {

	std::cout << id_str + "	Destructor called" << std::endl;
}

// -----------------------------------------------------------------------------

Brain &Brain:: operator = ( Brain const &src ) {

	std::cout << id_str + "	Copy assignment operator called" << std::endl;

	if ( this != &src )
		for ( int i = 0; i < N_IDEAS; ++i )
			_ideas[i] = src._ideas[i];
	return *this;
}
