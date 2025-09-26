/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:40:48 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/22 17:04:29 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <climits>
#include <iostream>
#include <list>

#define C_HI_Y	"\033[0;93m\001"
#define C_RST	"\033[0m\002"

static void			subjectsMain();
static void			subjectsMainWithList();
static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );

int	main()
{
	print_test_name( "Subject's main" );
	subjectsMain();
	print_test_name( "Subject's main with list" );
	subjectsMainWithList();
	std::cout << std::endl;
}

static void			subjectsMain()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

static void			subjectsMainWithList()
{
	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

/* -------------------------------------------------------------------------- */

static void print_test_name( std::string str )
{
	for ( size_t i = 0; i < str.size(); ++i )
		str[i] = std::toupper( str[i] );

	size_t width = str.length() + 10;

	std::string separator = n_chars( '-', width );
	std::cout << "\n" C_HI_Y << separator << '\n';
	std::cout << "**** " << str << " ****";
	std::cout << '\n' << separator << C_RST "\n";
	std::cout << std::endl;
}

static std::string n_chars( char c, size_t n )
{
	std::string str = "";
	while ( n-- )
		str += c;
	return str;
}
