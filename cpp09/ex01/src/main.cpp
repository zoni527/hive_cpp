/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:40:48 by jvarila           #+#    #+#             */
/*   Updated: 2025/10/06 11:19:28 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	rpn( std::string const &input );

int	main( int argc, char *argv[] )
{
	if ( argc != 2 )
	{
		std::cout << "Usage: ./RPN \"<list of operands and operators>\"" << std::endl;
		return 1;
	}
	rpn( argv[1] );
	return 0;
}
