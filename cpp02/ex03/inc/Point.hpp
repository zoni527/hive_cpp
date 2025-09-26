/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:08:00 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/17 10:57:06 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

public:
// ------------------------------------------------------------ member functions
	Fixed	getX() const;
	Fixed	getY() const;
// ---------------------------------------------------------------- constructors
	Point();
	Point( Point const &src );
	Point ( float const flt1, float const flt2 );
// ------------------------------------------------------------------ destructor
	~Point();
// ---------------------------------------------------------- operator overloads
	Point	&operator = ( Point const &src );

private:
	Fixed const	_x;
	Fixed const	_y;
};

bool	bsp( Point const a, Point const b, Point const c, Point const Point );

#endif
