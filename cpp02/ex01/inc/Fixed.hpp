/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:40:46 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/16 18:12:35 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed {

public:
// ------------------------------------------------------------ member functions
	int		getRawBits() const;
	void	setRawBits( int const raw );

	float	toFloat() const;
	int		toInt() const;
// ---------------------------------------------------------------- constructors
	Fixed();						// Default cqnstructor
	Fixed( Fixed const	&fixed );		// Copy constructor
	Fixed( int const	integer );		// Int constructor
	Fixed( float const	ifloat_num );	// Float constructor
// ------------------------------------------------------------------ destructor
	~Fixed();
// ---------------------------------------------------------- operator overloads
	Fixed	&operator = ( Fixed const &fixed );

private:
	int						_value;
	static unsigned const	_fractional_bits	= 8;

	static constexpr float	_power_of_two_float	= ( 1 << _fractional_bits );
};

std::ostream	&operator << ( std::ostream &os, Fixed const &fixed);

#endif
