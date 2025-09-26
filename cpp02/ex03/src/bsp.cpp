/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:24:58 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/17 14:21:10 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

typedef struct s_segment
{
	Fixed	dx;
	Fixed	dy;
}	t_segment;

bool bsp(const Point a, const Point b, const Point c, const Point Point) {

	t_segment ab { .dx = b.getX() - a.getX(), .dy = b.getY() - a.getY() };
	t_segment bc { .dx = c.getX() - b.getX(), .dy = c.getY() - b.getY() };
	t_segment ca { .dx = a.getX() - c.getX(), .dy = a.getY() - c.getY() };

	t_segment ap { .dx = Point.getX() - a.getX(), .dy = Point.getY() - a.getY() };
	t_segment bp { .dx = Point.getX() - b.getX(), .dy = Point.getY() - b.getY() };
	t_segment cp { .dx = Point.getX() - c.getX(), .dy = Point.getY() - c.getY() };

	// The cross product of two vectors that lay in the xy plane results in
	// a vector in the z direction. The sign of this vector depends on the
	// relation between the two vectors being operated on. If the point is
	// inside the triangle all of the cross products will have the same sign.
	// The size of the cross product represents the area of a parallelogram
	// defined by the two vectors. If this size is 0 it means that the two
	// vectors are on top of each other.

	Fixed ab_x_ap = ab.dx * ap.dy - ap.dx * ab.dy;
	Fixed bc_x_bp = bc.dx * bp.dy - bp.dx * bc.dy;
	Fixed ca_x_cp = ca.dx * cp.dy - cp.dx * ca.dy;

	if ( ab_x_ap == 0 || bc_x_bp == 0 || ca_x_cp == 0 )
		return false;

	Fixed zero;
	bool ab_x_ap_sign = ab_x_ap > zero;
	bool bc_x_bp_sign = bc_x_bp > zero;
	bool ca_x_cp_sign = ca_x_cp > zero;

	if (	ab_x_ap_sign != bc_x_bp_sign
		||	bc_x_bp_sign != ca_x_cp_sign
		||	ca_x_cp_sign != ab_x_ap_sign )
		return false;

	return true;
}
