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

/* -------------------------------------------------------------------------- */

std::vector<int const *>
&vec_pointers_recursion_sort(std::vector<int const *> &main_chain);

template<class T>
void	print_pairs_vec(std::vector< std::pair<T, T> > &pairs);

template<class T>
auto	vec_pairs_recursion(
	std::vector< std::pair<T, T> > &pairs);

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
