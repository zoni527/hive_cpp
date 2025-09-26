/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:28:22 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/05 22:48:29 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

unsigned const	Fixed:: _fractional_bits;
constexpr float	Fixed:: _power_of_two_float;

// ------------------------------------------------------------ member functions

int Fixed:: getRawBits() const {
	std::cout << "getRawBits member funtion called" << std::endl;
	return _value;
}

void Fixed:: setRawBits( int const raw ) {
	std::cout << "setRawBits member funtion called" << std::endl;
	_value = raw;
}

float Fixed:: toFloat() const {
	return ( _value / _power_of_two_float );
}

int Fixed:: toInt() const {
	return ( _value >> _fractional_bits );
}

// ---------------------------------------------------------------- constructors

Fixed:: Fixed()
: _value( 0 ) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed:: Fixed( Fixed const &fixed ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed:: Fixed( int const integer )
: _value ( integer << _fractional_bits ) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed:: Fixed( float const float_num )
: _value( roundf( float_num * _power_of_two_float ) ) {
	std::cout << "Float constructor called" << std::endl;
}

// ------------------------------------------------------------------ destructor

Fixed:: ~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// ---------------------------------------------------------- operator overloads

Fixed &Fixed:: operator = ( Fixed const &fixed ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &fixed )
		_value = fixed._value;
	return *this;
}

std::ostream &operator << ( std::ostream &os, Fixed const &fixed ) {
	return ( os << fixed.toFloat() );
}
