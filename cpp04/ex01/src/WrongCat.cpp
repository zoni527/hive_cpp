/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:05:12 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:13:35 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "ansi_colors.hpp"
#include <iostream>

std::string const	id_str = C_B_HI_G "WrongCat" C_RST;

// ------------------------------------------------------------ member functions

void WrongCat:: makeSound() const {

	std::cout << id_str + "	makes a sound: \"Meow!\"" << std::endl;
}

// ---------------------------------------------------------------- constructors

WrongCat:: WrongCat() {

	std::cout << id_str + "	Default constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat:: WrongCat( WrongCat const &src ) : WrongAnimal( src ) {

	std::cout << id_str + "	Copy constructor called" << std::endl;
}

// ------------------------------------------------------------------ destructor

WrongCat:: ~WrongCat() {

	std::cout << id_str + "	Destructor called" << std::endl;
}

// ---------------------------------------------------------- operator overloads

WrongCat &WrongCat:: operator = ( WrongCat const &src ) {

	std::cout << id_str + "	Copy assignment operator called" << std::endl;
	if (this != &src)
		WrongAnimal:: operator=( src );
	return *this;
}
