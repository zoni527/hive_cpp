/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:34:37 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/22 13:34:44 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <vector>

class Span
{
public:
	Span() = delete;
	Span( unsigned int N );
	~Span() = default;

	Span	&operator=( Span const &rhs );

	void	addNumber( int num );

	template<class T>
	void	addABunchOfNumbers(	typename T::iterator begin,
								typename T::iterator end )
	{
		if ( std::distance( begin, end ) + _ints.size() > _N )
			throw std::runtime_error(
				"Span: addABunchOfNumbers: "
				"addable element count exceeds element limit" );

		_ints.insert( _ints.end(), begin, end );
	}

	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	void			print() const;

private:
	unsigned int		_N;
	std::vector<int>	_ints;
};
