/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:06:17 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/09 17:07:52 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import "Point.hpp"

Fixed Point:: getX() const {
	return _x;
}

Fixed Point:: getY() const {
	return _y;
}

// ---------------------------------------------------------------- constructors

Point:: Point()
: _x( 0 ), _y( 0 ) {}

Point:: Point( Point const &src )
: _x( src._x ), _y( src._y ) {}

Point:: Point( float const flt1, float const flt2 )
: _x( Fixed( flt1 ) ), _y( Fixed( flt2 ) ) {}

// ------------------------------------------------------------------ destructor
Point:: ~Point() {}
// ---------------------------------------------------------- operator overloads

// Members are const, nothing to do
Point &Point:: operator = ( Point const &src ) {
	(void)src;
	return *this;
}
