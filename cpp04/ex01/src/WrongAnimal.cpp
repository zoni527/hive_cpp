/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:52:33 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:13:27 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "ansi_colors.hpp"
#include <iostream>

std::string const	id_str = C_B_HI_BL "WrongAnimal" C_RST;

// ------------------------------------------------------------ member functions

void WrongAnimal:: makeSound() const {

	std::cout << id_str + "	makes a sound: \"Yolo!\"" << std::endl;
}

std::string WrongAnimal:: getType() const {

	return _type;
}

// ---------------------------------------------------------------- constructors

WrongAnimal:: WrongAnimal() : _type( "WrongAnimal" ) {

	std::cout << id_str + "	Default constructor called" << std::endl;
}

WrongAnimal:: WrongAnimal( WrongAnimal const &src ) {

	std::cout << id_str + "	Copy constructor called" << std::endl;
	_type = src._type;
}

// ------------------------------------------------------------------ destructor

WrongAnimal:: ~WrongAnimal() {

	std::cout << id_str + "	Destructor called" << std::endl;
}

// ---------------------------------------------------------- operator overloads

WrongAnimal &WrongAnimal:: operator = ( WrongAnimal const &src ) {

	std::cout << id_str + "	Copy assignment operator called" << std::endl;
	if (this != &src)
		_type = src._type;
	return *this;
}
