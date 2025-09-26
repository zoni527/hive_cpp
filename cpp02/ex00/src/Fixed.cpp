/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:28:22 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/03 15:59:35 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// ------------------------------------------------------------ member functions

int Fixed:: getRawBits() const {
	std::cout << "getRawBits member funtion called" << std::endl;
	return _value;
}

void Fixed:: setRawBits( int const raw ) {
	std::cout << "setRawBits member funtion called" << std::endl;
	_value = raw;
}

// ---------------------------------------------------------------- constructors

Fixed:: Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed:: Fixed( Fixed const &fixed ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

// ------------------------------------------------------------------ destructor

Fixed:: ~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// ---------------------------------------------------------- operator overloads

Fixed &Fixed:: operator =( Fixed const &fixed ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &fixed )
		_value = fixed.getRawBits();
	return *this;
}
