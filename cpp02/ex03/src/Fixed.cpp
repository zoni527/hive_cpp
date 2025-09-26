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
 * 1000 0000 | 0000 0000 | 1111 1111 | 0000 0000
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

	/**
	 * At one point I thought of constructing the float by using base 10, but
	 * that would have caused some bad wrangling of bytes, which would have
	 * been difficult and unnecessary.
	 * -------------------------------------------------------------------------
	 *
	 * Found this clever trick to make bit masks on reddit:
	 * if _fractional_bits = 8:
	 * -> 1				= 0b 0000 0000 0000 0001 = 1
	 * -> 1 << 8		= 0b 0000 0001 0000 0000 = 256
	 * -> (1 << 8) - 1	= 0b 0000 0000 1111 1111 = 255
	 */

	/**
	 * int fractional_bits = value & ( ( 1 << _fractional_bits ) - 1 );
	 *
	 * float fractional_part = static_cast<float>(fractional_bits);
	 * for ( int i = 0; i < _fractional_bits; ++i )
	 * 	fractional_part /= 10;
	 *
	 * int whole_bits = _value >> _fractional_bits;
	 * float whole_part = static_cast<float>(whole_bits);
	 *
	 * return whole_part + fractional_part;
	 */
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

// Default constructor
Fixed:: Fixed() : _value( 0 ) {}

// Copy constructor
Fixed:: Fixed( Fixed const &fixed ) {
	*this = fixed;
}

// Int constructor
Fixed:: Fixed( int const integer ) {
	 _value = ( integer << _fractional_bits );

	// This portion of code I used to have for checking if the original integer
	// would fit in the int type in the system when shifted fractional bits to
	// the left. The division is done instead of shifting back due to the
	// undefined behaviour of right shifting signed integers (division isn't
	// UB). After discussions with peers I agree that the type should be fast.
/**
	int shift_left = ( ( integer << _fractional_bits ) );
	if ( shift_left / _power_of_two_int != integer )
		std::cout << "WARNING! Number can't be simply shifted without corruption" << std::endl;
*/
}

// Float constructor
Fixed:: Fixed( float const float_num ) {
	_value = roundf( float_num * _power_of_two_float );

	// 123.456...
	// Whole part = 123
/**
	int whole_part = static_cast<int>( float_num );
	if ( ( ( whole_part << _fractional_bits ) >> _fractional_bits ) != whole_part )
		std::cout << "WARNING! Number can't be simply shifted without corruption" << std::endl;
*/

	// Float part = .456...
	// Get _fractional_bits real bytes
/**
	float temp = float_num;
	for ( int i = 0; i < _fractional_bits; ++i )
		temp *= 10;
	temp = 4567 8901.234...
	int fractional_part = static_cast<int>(temp);
	_value = whole_part | fractional_part;
*/
}

// ------------------------------------------------------------------ destructor
Fixed:: ~Fixed() {}
// --------------------------------------------------- member operator overloads

Fixed &Fixed:: operator = ( Fixed const &fixed ) {
	if ( this != &fixed )
		_value = fixed._value;
	return *this;
}

// Increment and decrement

Fixed &Fixed:: operator ++ () {
	++_value;
	return *this;
}

Fixed &Fixed:: operator -- (void ) {
	--_value;
	return *this;
}

Fixed Fixed:: operator ++ ( int ) {
	Fixed temp( *this );
	++_value;
	return temp;
}

Fixed Fixed:: operator -- ( int ) {
	Fixed temp( *this );
	--_value;
	return temp;
}

// Comparison operators

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

// Arithmetic Fixed:: operators

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
