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

#include <iostream>
#include <vector>

#define DEBUG
#define C_B_HI_Y	"\033[1;93m\001"
#define C_B_HI_G	"\033[1;92m\001"
#define C_RST		"\033[0m\002"

/* -------------------------------------------------------------------------- */

std::vector<int const *>
&vec_pointers_recursion_sort(std::vector<int const *> &main_chain);

/* -------------------------------------------------------------------------- */

template<class T>
T	&merge_insertion_sort_vec(T &container)
{
	if (container.size() < 2)
		return container;

#ifdef DEBUG
	std::cout << "Original container:\n";
	for (auto const &e : container)
		std::cout << e << " ";
	std::cout << "\n";
#endif

	// Use vector if integer pointers for recursive sorting
	std::vector<int const *>	main_chain;

	for (auto const &e : container) {
		main_chain.push_back(&e);
	}

	vec_pointers_recursion_sort(main_chain);
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
