/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:09:22 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:15:36 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "ansi_colors.hpp"
#include <iostream>

std::string const	id_str = C_B_HI_B "Cat" C_RST;

// ------------------------------------------------------------ member functions

void Cat:: makeSound() const {

	std::cout << id_str + "	makes a sound: \"Meow!\"" << std::endl;
}

// ---------------------------------------------------------------- constructors

Cat:: Cat() {

	std::cout << id_str + "	Default constructor called" << std::endl;
	_type = "Cat";
}

Cat:: Cat( Cat const &src ) : Animal( src ) {

	std::cout << id_str + "	Copy constructor called" << std::endl;
}

// ------------------------------------------------------------------ destructor

Cat:: ~Cat() {

	std::cout << id_str + "	Destructor called" << std::endl;
}

// ---------------------------------------------------------- operator overloads

Cat &Cat:: operator = ( Cat const &src ) {

	std::cout << id_str + "	Copy assignment operator called" << std::endl;
	if (this != &src)
		Animal:: operator=( src );
	return *this;
}
