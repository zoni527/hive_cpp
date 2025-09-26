/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:28:22 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/09 11:57:32 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <ostream>
#include <cmath>

unsigned const	Fixed:: _fractional_bits;
constexpr float	Fixed:: _power_of_two_float;

/** Some notes about fixed point
 *
 * A four byte int (int32_t) in binary looks like this:
 *
 * sddd dddd | dddd dddd | dddd dddd | dddd dddd
 *
 * where s is the sign bit and d is a binary digit, determining the size of the
 * number.
 *
 * A fixed point number uses an int as storage for two kinds of bits: some for
 * the whole part and some for the fractional part. They are used to benefit
 * from doing valid integer calculations that are cheap and fast to compute
 * numbers that have a whole and fractional part.
 *
 * With 8 fractional bits the bit sequence for a fixed point would look like this:
 *
 * swww wwww | wwww wwww | wwww wwww | ffff ffff
 *
 * I am not 100% about the sign bit, but as I have read that bitshifting signed
 * integers is undefined behaviour (UB), I err on the side of caution and instead
 * of using bitshifts use division and multiplication by powers of two. These
 * correspond to shifting the bit sequence, like timing by powers of 10 shifts
 * in base 10.
 *
 * --> UPDATE: in C++ 20 sign is guaranteed to be maintained in shifts.
 *
 * -> 1234 * 100
 *  = 1234 * 10 * 10
 *  = 12340 * 10
 *  = 123400
 *
 * -> 0b 11 * 4
 *  = 0b 11 * 2 * 2
 *  = 0b 110 * 2
 *  = 0b 1100
 *
 * Max possible positive number without fractional part:
 *
 * -> 0x        7f |        ff |        ff |        00 >> 8
 *  = 0b 0111 1111 | 1111 1111 | 1111 1111 | 0000 0000 >> 8
 *  = 0b 0000 0000 | 0111 1111 | 1111 1111 | 1111 1111
 *	= 8388607
 *
 * Max possible float: 8388607.99609375 = 0x 7f ff ff ff / 256f
 *
 */

// ------------------------------------------------------------ member functions

int Fixed:: getRawBits() const {
	return _value;
}

void Fixed:: setRawBits( int const raw ) {
	_value = raw;
}

float Fixed:: toFloat() const {
	return ( _value / _power_of_two_float );
}

int Fixed:: toInt() const {
	return ( _value >> _fractional_bits );
}

// ----------------------------------------------------- static member functions

Fixed &Fixed:: min( Fixed &f1, Fixed &f2 ) {
	if ( f2._value < f1._value )
		return f2;
	return f1;
}

 Fixed &Fixed:: max( Fixed &f1, Fixed &f2 ) {
	if ( f2._value > f1._value )
		return f2;
	return f1;
}

Fixed const &Fixed:: min( const Fixed &f1, const Fixed &f2 ) {
	if ( f2._value < f1._value )
		return f2;
	return f1;
}

const Fixed &Fixed:: max( const Fixed &f1, const Fixed &f2 ) {
	if ( f2._value > f1._value )
		return f2;
	return f1;
}

// ---------------------------------------------------------------- constructors

Fixed:: Fixed() : _value( 0 ) {}

Fixed:: Fixed( Fixed const &fixed ) {
	*this = fixed;
}

Fixed:: Fixed( int const integer )
: _value( integer << _fractional_bits ) {}

Fixed:: Fixed( float const float_num ) 
: _value( roundf( float_num * _power_of_two_float ) ) {}

// ------------------------------------------------------------------ destructor
Fixed:: ~Fixed() {}
// --------------------------------------------------- member operator overloads

Fixed &Fixed:: operator = ( Fixed const &fixed ) {
	if ( this != &fixed )
		_value = fixed._value;
	return *this;
}

// Preincrement
Fixed &Fixed:: operator ++ () {
	++_value;
	return *this;
}

// Predecrement
Fixed &Fixed:: operator -- (void ) {
	--_value;
	return *this;
}

// Postincrement
Fixed Fixed:: operator ++ ( int ) {
	Fixed temp( *this );
	++_value;
	return temp;
}

// Postdecrement
Fixed Fixed:: operator -- ( int ) {
	Fixed temp( *this );
	--_value;
	return temp;
}

// Comparison operator overloads

bool Fixed:: operator > ( Fixed const &fixed ) const {
	return ( _value > fixed._value );
}

bool Fixed:: operator < ( Fixed const &fixed) const {
	return ( _value < fixed._value );
}

bool Fixed:: operator >= ( Fixed const &fixed ) const {
	return ( _value >= fixed._value );
}

bool Fixed:: operator <= ( Fixed const &fixed ) const {
	return ( _value <= fixed._value );
}

bool Fixed:: operator == ( Fixed const &fixed ) const {
	return ( _value == fixed._value );
}

bool Fixed:: operator != ( Fixed const &fixed ) const {
	return ( _value != fixed._value );
}

// Arithmetic operator overloads

Fixed Fixed:: operator + ( Fixed const &fixed ) const {
	Fixed sum;
	sum.setRawBits( _value + fixed._value );
	return sum;
}

Fixed Fixed:: operator - ( Fixed const &fixed ) const {
	Fixed difference;
	difference.setRawBits( _value - fixed._value );
	return difference;
}

Fixed Fixed:: operator * ( Fixed const &fixed ) const {
	Fixed product;
	product.setRawBits( ( static_cast<int64_t>( _value ) * fixed._value ) >> _fractional_bits);
	return product;
}

Fixed Fixed:: operator / ( Fixed const &fixed ) const {
	Fixed quotient;
	quotient.setRawBits( ( _value << _fractional_bits ) / fixed._value );
	return quotient;
}

// ----------------------------------------------- non member operator overloads

std::ostream &operator << ( std::ostream &os, Fixed const &fixed ) {
	return ( os << fixed.toFloat() );
}
