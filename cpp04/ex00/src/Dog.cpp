/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:54:30 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:15:30 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "ansi_colors.hpp"
#include <iostream>

std::string const	id_str = C_B_HI_R "Dog" C_RST;

// ------------------------------------------------------------ member functions

void Dog:: makeSound() const {

	std::cout << id_str + "	makes a sound: \"Woof!\"" << std::endl;
}

// ---------------------------------------------------------------- constructors

Dog:: Dog() {

	std::cout << id_str + "	default constructor called" << std::endl;
	_type = "Dog";
}

Dog:: Dog( Dog const &src ) : Animal( src ) {

	std::cout << id_str + "	copy constructor called" << std::endl;
}

// ------------------------------------------------------------------ destructor

Dog:: ~Dog() {

	std::cout << id_str + "	destructor called" << std::endl;
}

// ---------------------------------------------------------- operator overloads

Dog &Dog:: operator = ( Dog const &src ) {

	std::cout << id_str + "	copy assignment operator called" << std::endl;
	if (this != &src)
		Animal:: operator=( src );
	return *this;
}
