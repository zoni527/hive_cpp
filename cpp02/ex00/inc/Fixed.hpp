/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:40:46 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/16 18:13:08 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FIXED_H
# define FIXED_H

// Welcome to Orthodoc Canonical Form!

class Fixed {

public:
// ------------------------------------------------------------ member functions
	int		getRawBits() const;
	void	setRawBits( int const raw );
// ---------------------------------------------------------------- constructors
	Fixed();					// Default constructor
	Fixed( Fixed const &fixed );	// Copy constructor
// ------------------------------------------------------------------ destructor
	~Fixed();
// ---------------------------------------------------------- operator overloads
	Fixed &operator = ( Fixed const &fixed ); // Copy assignment operator

private:
	int						_value;
	static unsigned const	_fractional_bits = 8;
};

#endif
