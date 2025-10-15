/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:34:56 by jvarila           #+#    #+#             */
/*   Updated: 2025/10/13 16:48:00 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>

#define C_B_HI_Y	"\033[1;93m\001"
#define C_B_HI_G	"\033[1;92m\001"
#define C_B_HI_W	"\033[1;97m\001"
#define C_RST		"\033[0m\002"

/* -------------------------------------------------------------------------- */

constexpr uint8_t	FW_01 = 10;	// Field width
constexpr uint8_t	PRINT_LIMIT = 10;

/* -------------------------------------------------------------------------- */

std::vector<int const *>
&vec_pointers_recursion_sort(std::vector<int const *> &main_chain);

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
T	&merge_insertion_sort_vec(T &container)
{
	limited_print_container(container, "Before:");
	write_to_file(container, "unsorted.txt");
	// Use vector if integer pointers for recursive sorting
	std::vector<int const *>	main_chain;

	for (auto const &e : container) {
		main_chain.push_back(&e);
	}

	vec_pointers_recursion_sort(main_chain);

	T	sorted_container;
	for (auto const &e : main_chain)
		sorted_container.insert(sorted_container.end(), *e);
	std::swap(container, sorted_container);
	limited_print_container(container, "After:");
	write_to_file(container, "sorted.txt");
	return container;
}

/**
 * 0  1  2  3  4  5  ...
 * a1 a2 a3 a4 a5 a6 ...
 * b1 b2 b3 b4 b5 b6 ...
 *
 * Jacobsthal number:		3
 * Limiting element:		a3
 * Limiting element index:	2 = Jacobsthal number - 2 + 1
 *
 * Insertion of b1 ->
 *
 * v
 * 0  1  2  3  4  5  6  ...
 * b1 a1 a2 a3 a4 a5 a6 ...
 *          ^
 *
 * Limiting element index:	3 = Jacobsthal number - 2 + 2
 *
 * Insertion of b3 ->
 *
 *    v
 * 0  1  2  3  4  5  6  7  8  9...
 * b1 b3 a1 a2 a3 a4 a5 a6 a7 a8...
 *             ^
 * Limiting element index:	4 = Jacobsthal number - 2 + 3
 *
 * Insertion of b2 ->
 *
 *          v
 * 0  1  2  3  4  5  6  7  8  9  10...
 * b1 b3 a1 b2 a2 a3 a4 a5 a6 a7 a8...
 *                ^
 *
 * Jacobsthal number:		5
 * Limiting element:		a5
 * Limiting element index:	7 = Jacobsthal number - 2 + 4
 *
 * 0  1  2  3  4  5  6  7  8  9...
 * b1 b3 a1 b2 a2 a3 a4 a5 a6 a7 a8...
 */
