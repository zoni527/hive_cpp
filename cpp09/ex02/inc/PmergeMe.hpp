/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:34:56 by jvarila           #+#    #+#             */
/*   Updated: 2025/10/15 17:19:39 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <deque>
#include <list>

#define C_B_HI_Y	"\033[1;93m\001"
#define C_B_HI_G	"\033[1;92m\001"
#define C_B_HI_W	"\033[1;97m\001"
#define C_RST		"\033[0m\002"

/* -------------------------------------------------------------------------- */

constexpr uint8_t	FW_01 = 10;	// FW = Field width
constexpr uint8_t	PRINT_LIMIT = 10;

/* -------------------------------------------------------------------------- */

std::vector<int const *>
&vector_of_pointers_recursion_sort(std::vector<int const *> &main_chain);

std::deque<int const *>
&deque_of_pointers_recursion_sort(std::deque<int const *> &source_chain);

std::list<int const *>
&list_of_pointers_recursion_sort(std::list<int const *> &source_chain);

template<class Input, class Calc>
Input	&merge_insertion_sort_generic(Input &input);

/* -------------------------------------------------------------------------- */

template<class T>
void	print_container(T const &cont, std::string const &str)
{
	std::cout << std::left << std::setw(FW_01) << str;
	for (auto it = cont.cbegin(); it != cont.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template<class T>
void	limited_print_container(T const &cont, std::string const &str)
{
	if (cont.size() <= PRINT_LIMIT) {
		print_container(cont, str);
		return;
	}

	size_t	half	= PRINT_LIMIT / 2;
	size_t	remain	= half;

	if (PRINT_LIMIT % 2 != 0)
		++remain;

	std::cout << std::left << std::setw(FW_01) << str;
	auto	it = cont.cbegin();
	auto	end = it;

	std::advance(end, half);
	for (; it != end; ++it)
		std::cout << *it << " ";
	std::cout << "... ";
	it = cont.begin();
	std::advance(it, cont.size() - remain);
	for (; it != cont.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template<class T>
void	write_to_file(T const &cont, std::string const &file_name)
{
	std::ofstream	ofs(file_name);
	if (!ofs) {
		std::cerr << "ERROR: couldn't open output file" << std::endl;
		return;
	}
	for (auto const &e : cont)
		ofs << e << "\n";
}

template<class T>
T	&merge_insertion_sort(T &container)
{
	std::vector<int const *>	vector_chain;
	std::deque<int const *>		deque_chain;
	std::list<int const *>		list_chain;

	for (auto const &e : container) {
		vector_chain.push_back(&e);
		deque_chain.push_back(&e);
		list_chain.push_back(&e);
	}

	auto start	= std::chrono::high_resolution_clock::now();
	vector_of_pointers_recursion_sort(vector_chain);
	auto stop	= std::chrono::high_resolution_clock::now();
	std::chrono::duration<double>	vector_seconds = stop - start;
	auto							vector_microseconds = vector_seconds * 1000000;

	start	= std::chrono::high_resolution_clock::now();
	deque_of_pointers_recursion_sort(deque_chain);
	stop	= std::chrono::high_resolution_clock::now();
	std::chrono::duration<double>	deque_seconds = stop - start;
	auto							deque_microseconds = deque_seconds * 1000000;

	start	= std::chrono::high_resolution_clock::now();
	list_of_pointers_recursion_sort(list_chain);
	stop	= std::chrono::high_resolution_clock::now();
	std::chrono::duration<double>	list_seconds = stop - start;
	auto							list_microseconds = list_seconds * 1000000;

	T	sorted_container;
	for (auto const &e : deque_chain)
		sorted_container.insert(sorted_container.end(), *e);
	std::swap(container, sorted_container);
	limited_print_container(container, "After:");

	std::cout	<< "Time to process range of " << sorted_container.size()
				<< " elements with std::vector : " << vector_microseconds.count() << " us\n";
	std::cout	<< "Time to process range of " << sorted_container.size()
				<< " elements with std::deque  : " << deque_microseconds.count() << " us\n";
	std::cout	<< "Time to process range of " << sorted_container.size()
				<< " elements with std::list   : " << list_microseconds.count() << " us\n";

	write_to_file(container, "sorted.txt");
	return container;
}

template<class Input, class Calc>
Input &merge_insertion_sort_generic(Input &input)
{
	Calc	cont(input.cbegin(), input.cend());

	for (auto const &e : cont)
		std::cout << e << " ";
	std::cout << std::endl;

	(void)cont;

	return input;
}
