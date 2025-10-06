/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:08:30 by jvarila           #+#    #+#             */
/*   Updated: 2025/10/06 15:52:38 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <regex>
#include <limits>

void	rpn( std::string const &input )
{
	std::stringstream	inputStream( input );

	if ( !inputStream )
	{
		std::cerr << "Error: couldn't open input string stream" << std::endl;
		return;
	}
	std::regex			numFormat( R"(^[+-]?\d+$)" );
	std::string const	supportedOperands = "+-/*";
	std::stack<int>		operands;
	std::string			token;
	size_t				operationCount = 0;

	while ( inputStream >> token )
	{
		// If the token is a number
		if ( std::regex_match( token, numFormat ) )
		{
			try
			{
				operands.push( std::stoi( token ) );
			}
			catch ( std::exception const &e )
			{
				std::cerr << "Error: token overflows int" << std::endl;
				return;
			}
		}
		// If the token is an operator
		else if ( token.size() == 1
			&& std::any_of(	supportedOperands.cbegin(), supportedOperands.cend(),
							[ &t = token[0] ]( auto &c ) { return t == c; } ) )
		{
			if ( operands.size() < 2 )
			{
				std::cerr << "Error: not enough operands in stack" << std::endl;
				return;
			}

			int			lhs;
			int			rhs;
			long long	result;

			rhs = operands.top();
			operands.pop();
			lhs = operands.top();
			operands.pop();

			switch ( token[0] )
			{
				case '+':
					result = static_cast<long long>( lhs ) + rhs;
					break;
				case '-':
					result = static_cast<long long>( lhs ) - rhs;
					break;
				case '*':
					result = static_cast<long long >( lhs ) * rhs;
					break;
				case '/':
					if ( rhs == 0 )
					{
						std::cerr << "Error: division by zero" << std::endl;
						return;
					}
					result = lhs / rhs;
					break;
				default:
					std::cerr << "Error: unknown operator" << std::endl;
					return;
			}

			if ( result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min() )
			{
				std::cerr << "Error: int overflow during calculation" << std::endl;
				return;
			}
			++operationCount;
			operands.push( result );
		}
		// Invalid token
		else
		{
			std::cerr << "Error: invalid token: " << token << std::endl;
			return;
		}
	}
	if ( operationCount == 0 )
	{
		std::cerr << "Error: no operators given" << std::endl;
		return;
	}
	if ( operands.size() != 1 )
	{
		std::cerr << "Error: not enough operators" << std::endl;
		return;
	}
	std::cout << operands.top() << std::endl;
}
