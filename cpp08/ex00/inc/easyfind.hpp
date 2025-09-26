/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:02:37 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/19 17:06:41 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>

class notFoundException : public std::exception
{
public:
	const char	*what() const noexcept override
	{
		return "Element not found in container";
	}
};

template<typename T>
auto	easyfind( T &cont, int num )
{
	auto	iter = std::find( cont.begin(), cont.end(), num );

	if ( iter == cont.end() )
		throw notFoundException();
	return iter;
}
