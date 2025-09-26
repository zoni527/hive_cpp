/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:09:52 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/11 16:17:27 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class ScalarConverter
{
public:
	ScalarConverter() = delete;
	ScalarConverter( ScalarConverter const &other ) = delete;
	~ScalarConverter() = default;

	ScalarConverter	&operator=( ScalarConverter const &rhs ) = delete;

	static void	convert( std::string const &str );
};
