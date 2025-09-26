/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:46:37 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/09 19:44:03 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "ansi_colors.hpp"
#include <iostream>

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );
static void			binary_operator_test( Fixed const &f1, Fixed const &f2,
								   std::string op);
static void			test_suite_comparison( std::string op );
static void			test_suite_arithmetic( std::string op );

int main() {

	print_test_name( "Subject's main (with better formatting)" );
	// -------------------------------------------------------------------------
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << "\n\n";
		std::cout << ++a << "\n";
		std::cout << a << "\n\n";;
		std::cout << a++ << "\n";;
		std::cout << a << "\n\n";;

		std::cout << b << "\n\n";;

		std::cout << Fixed::max( a, b ) << "\n";
	}
	// -------------------------------------------------------------------------
	print_test_name( "Additional testing: >" );
	test_suite_comparison(">");
	print_test_name( "Additional testing: <" );
	test_suite_comparison("<");
	print_test_name( "Additional testing: >=" );
	test_suite_comparison(">=");
	print_test_name( "Additional testing: <=" );
	test_suite_comparison("<=");
	print_test_name( "Additional testing: ==" );
	test_suite_comparison("==");
	print_test_name( "Additional testing: !=" );
	test_suite_comparison("!=");
	print_test_name( "Additional testing: +" );
	test_suite_arithmetic("+");
	print_test_name( "Additional testing: -" );
	test_suite_arithmetic("-");
	print_test_name( "Additional testing: *" );
	test_suite_arithmetic("*");
	print_test_name( "Additional testing: /" );
	test_suite_arithmetic("/");
	print_test_name( "Additional testing: pre and post incrementation and decrementation");
	{
		Fixed zero;
		Fixed ft( 42.0f );
		std::cout << "Before preincrement:	" << zero << "\n";
		std::cout << "During preincrement:	" << ++zero << "\n";
		std::cout << "After preincrement:	" << zero << "\n\n";
		std::cout << "Before predecrement:	" << zero << "\n";
		std::cout << "During predecrement:	" << --zero << "\n";
		std::cout << "After predecrement:	" << zero << "\n\n";
		std::cout << "Before postincrement:	" << zero << "\n";
		std::cout << "During postincrement:	" << zero++ << "\n";
		std::cout << "After postincrement:	" << zero << "\n\n";
		std::cout << "Before postdecrement:	" << zero << "\n";
		std::cout << "During postdecrement:	" << zero-- << "\n";
		std::cout << "After postdecrement:	" << zero << "\n\n";
	}
	std::cout << std::endl;
	return 0;
}

// ------------------------------------------------------------ static functions

static void print_test_name( std::string str ) {

	for ( char &c : str )
		c = std::toupper( c );

	size_t width = str.length() + 10;

	std::string separator = n_chars( '-', width );
	std::cout << "\n" C_HI_Y << separator << "\n";
	std::cout << "**** " << str << " ****";
	std::cout << "\n" << separator << C_RST "\n";
	std::cout << std::endl;
}

static std::string n_chars( char c, size_t n ) {
	std::string str = "";
	while ( n-- )
		str += c;
	return str;
}

static void binary_operator_test( Fixed const &f1, Fixed const &f2,
								   std::string op) {

	std::cout << "Operation:	" << f1 << " " + op + " " << f2 << "\n";

	bool bool_result = false;
	if (	op == ">"
		||	op == "<"
		||	op == ">="
		||	op == "<="
		|| 	op == "=="
		|| 	op == "!=")
		bool_result = true;

	if ( bool_result ) {
		if (op == ">")
			bool_result = f1 > f2;
		else if (op == "<")
			bool_result = f1 < f2;
		else if (op == ">=")
			bool_result = f1 >= f2;
		else if (op == "<=")
			bool_result = f1 <= f2;
		else if (op == "==")
			bool_result = f1 == f2;
		else if (op == "!=")
			bool_result = f1 != f2;

		std::cout << "Result:		";
		if (bool_result)
			std::cout << "true\n";
		else
			std::cout << "false\n";
		std::cout << std::endl;
		return;
	}

	Fixed fixed_result;
	if ( op == "+" )
		fixed_result = f1 + f2;
	else if ( op == "-" )
		fixed_result = f1 - f2;
	else if ( op == "*" )
		fixed_result = f1 * f2;
	else if ( op == "/" ) {
		if ( f2.getRawBits() == 0 ) {
			std::cout << "Division by zero, skipping\n" << std::endl;
			return;
		}
		fixed_result = f1 / f2;
	}
	std::cout << "Result:		" << fixed_result << "\n" << std::endl;
}

static void test_suite_comparison(std::string op) {
	binary_operator_test( Fixed( 0 ), Fixed( 0 ), op );
	binary_operator_test( Fixed( 1 ), Fixed( 0 ), op );
	binary_operator_test( Fixed( 0 ), Fixed( 1 ), op );
	binary_operator_test( Fixed( 1 ), Fixed( 1 ), op );
	binary_operator_test( Fixed( 1 ), Fixed( -1 ), op );
	binary_operator_test( Fixed( -1 ), Fixed( 1 ), op );
	binary_operator_test( Fixed( -1 ), Fixed( -1 ), op );
	binary_operator_test( Fixed( 2 ), Fixed( 1 ), op );
	binary_operator_test( Fixed( 1 ), Fixed( 2 ), op );
	binary_operator_test( Fixed( 10 ), Fixed( 0 ), op );
	binary_operator_test( Fixed( 0 ), Fixed( 10 ), op );
	binary_operator_test( Fixed( -10 ), Fixed( 0 ), op );
	binary_operator_test( Fixed( 0 ), Fixed( -10 ), op );
	binary_operator_test( Fixed( 0.5f ), Fixed( 0.4f ), op );
	binary_operator_test( Fixed( 0.4f ), Fixed( 0.5f ), op );
	binary_operator_test( Fixed( -0.5f ), Fixed( -0.4f ), op );
	binary_operator_test( Fixed( -0.4f ), Fixed( -0.5f ), op );
}

static void test_suite_arithmetic(std::string op) {
	binary_operator_test( Fixed( 0 ), Fixed( 0 ), op );
	binary_operator_test( Fixed( 1 ), Fixed( 0 ), op );
	binary_operator_test( Fixed( 0 ), Fixed( 1 ), op );
	binary_operator_test( Fixed( 1 ), Fixed( 1 ), op );
	binary_operator_test( Fixed( 1 ), Fixed( -1 ), op );
	binary_operator_test( Fixed( -1 ), Fixed( 1 ), op );
	binary_operator_test( Fixed( -1 ), Fixed( -1 ), op );
	binary_operator_test( Fixed( 2 ), Fixed( 2 ), op );
	binary_operator_test( Fixed( 3 ), Fixed( 3 ), op );
	binary_operator_test( Fixed( 1 ), Fixed( 3 ), op );
	binary_operator_test( Fixed( 2 ), Fixed( 3 ), op );
	binary_operator_test( Fixed( 5 ), Fixed( 4 ), op );
	binary_operator_test( Fixed( 4 ), Fixed( 0.5f ), op );
	binary_operator_test( Fixed( 100 ), Fixed( 0.01f ), op );
}
