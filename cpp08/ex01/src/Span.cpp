/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:13:15 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/22 13:16:00 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <numeric>
#include <iostream>

Span:: Span( unsigned int N )
	: _N( N ) {}

Span	&Span:: operator=( Span const &rhs )
{
	if ( this != &rhs )
		_ints = rhs._ints;

	return *this;
}

void	Span:: addNumber( int num )
{
	if ( _ints.size() >= _N )
		throw std::runtime_error( "Span: addNumber: element limit exceeded" );
	_ints.push_back( num );
}

unsigned int	Span:: shortestSpan() const
{
	if ( _ints.size() < 2 )
		throw std::runtime_error(
			"Span: shortestSpan: "
			"can't calculate spans for less than two elements" );

	std::vector<int>			sorted( _ints );
	std::vector<unsigned int>	spans( _N, 0 );

	std::sort( sorted.begin(), sorted.end() );
	std::adjacent_difference( sorted.begin(), sorted.end(), spans.begin() );

	return *std::min_element( spans.begin() + 1, spans.end() );
}

unsigned int	Span:: longestSpan() const
{
	if ( _ints.size() < 2 )
		throw std::runtime_error(
			"Span: longestSpan: "
			"can't calculate spans for less than two elements" );

	int const	max = *std::max_element( _ints.cbegin(), _ints.cend() );
	int const	min = *std::min_element( _ints.cbegin(), _ints.cend() );

	return ( max - min );
}

void	Span:: print() const
{
	if ( _ints.empty() )
	{
		std::cout << "Empty span" << std::endl;
		return;
	}
	for ( auto const &i : _ints )
		std::cout << i << " ";
	std::cout << std::endl;
}
