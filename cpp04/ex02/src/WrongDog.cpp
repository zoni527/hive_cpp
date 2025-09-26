/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:17:43 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:13:52 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"
#include "ansi_colors.hpp"
#include <iostream>

std::string const	id_str = C_B_HI_P "WrongDog" C_RST;

// ------------------------------------------------------------ member functions

void WrongDog:: makeSound() const {

	std::cout << id_str + "	makes a sound: \"Woof!\"" << std::endl;
}

// ---------------------------------------------------------------- constructors

WrongDog:: WrongDog() {

	std::cout << id_str + "	Default constructor called" << std::endl;
	_type = "WrongDog";
}

WrongDog:: WrongDog( WrongDog const &src ) : WrongAnimal( src ) {

	std::cout << id_str + "	Dopy constructor called" << std::endl;
}

// ------------------------------------------------------------------ destructor

WrongDog:: ~WrongDog() {

	std::cout << id_str + "	Destructor called"	<< std::endl;
}

// ---------------------------------------------------------- operator overloads

WrongDog &WrongDog:: operator = ( WrongDog const &src ) {

	std::cout << id_str + "	Dopy assignment operator called" << std::endl;
	if (this != &src)
		WrongAnimal:: operator=( src );
	return *this;
}
