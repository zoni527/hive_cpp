/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:45:52 by jvarila           #+#    #+#             */
/*   Updated: 2025/10/13 19:15:05 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <unordered_map>
#include <algorithm>

constexpr uint8_t	RECURSION_OFFSET = 5;

void	print_chain( std::string const &name,
				 std::string const &indent,
				 std::vector<int const *> vec)
{
	std::cout << indent << name << ":\n" << indent;
	for (auto const &e : vec)
		std::cout << *e << " ";
	std::cout << std::endl;
}

std::vector<int const *>
&vec_pointers_recursion_sort(std::vector<int const *> &source_chain)
{
#ifdef DEBUG
	static size_t	recursion_level = 0;

	++recursion_level;
	std::string	indent(recursion_level * RECURSION_OFFSET, ' ');
	std::cout << indent << "//////////////////////////////////\n";
	print_chain("Source chain", indent, source_chain);
#endif

	if (source_chain.size() <= 1) {
#ifdef DEBUG
		std::cout << indent << R"(\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\)" << "\n";
#endif
		return source_chain;
	}

	auto	straggler	= source_chain.back();
	bool	not_even	= (source_chain.size() % 2 != 0);

	if (not_even)				// Ensure iterator lands on end() when incrementing by 2
		source_chain.pop_back();

	/**
	 * Save main chain elements as a vector of int pointers to the original
	 * source_chain, associate matching pend chain elements using an unordered map
	 * (hash map), consisting of pointer to pointer mappings
	 */
	std::vector<int const *>						main_chain;
	std::unordered_map<int const *, int const *>	pair_map;

#ifdef DEBUG
		std::cout << indent << "Pairs:\n" << indent;
#endif
	for (auto i = source_chain.begin(); i != source_chain.end(); i += 2) {
		auto	&ptr_1 = *i;
		auto	&ptr_2 = *(i + 1);

#ifdef DEBUG
		std::cout << "{" << *ptr_1 << ", " << *ptr_2 << "} ";
#endif

		if (*ptr_2 < *ptr_1) {
			main_chain.push_back(ptr_1);	// Larger element goes to main chain
			pair_map.emplace(ptr_1, ptr_2);
		} else {
			main_chain.push_back(ptr_2);
			pair_map.emplace(ptr_2, ptr_1);
		}
	}
#ifdef DEBUG
		std::cout << "\n";
#endif

	if (not_even)
		source_chain.push_back(straggler);

#ifdef DEBUG
	print_chain("Main chain (unsorted)", indent, main_chain);
#endif

	vec_pointers_recursion_sort(main_chain);

#ifdef DEBUG
	print_chain("Main chain (sorted)", indent, main_chain);
#endif

	std::vector<int const *>	pend_chain;
	for (auto it = main_chain.begin(); it != main_chain.end(); ++it)
		pend_chain.push_back(pair_map[*it]);
	if (not_even)
		pend_chain.push_back(straggler);

#ifdef DEBUG
	std::cout << indent << "Pend chain:\n";
	std::cout << indent;
	for (auto iptr : pend_chain)
		std::cout << *iptr << " ";
	std::cout << "\n";
#endif

	// Put b1 before a1
	main_chain.insert(main_chain.begin(), pend_chain.front());
#ifdef DEBUG
	print_chain("Main chain with b1 inserted", indent, main_chain);
#endif

	using It = decltype(main_chain.begin());
	size_t	insertions			= 1;		// b1 was already inserted
	size_t	previous_jacobstahl	= 1;		// b1 insertion corresponds to Jacobstahl 1
	size_t	current_jacobstahl	= 3;		// Continue to b3 and b2
	size_t	element_idx			= 0;
	size_t	elements_to_insert	= 0;
	It		upper_limit			= main_chain.begin() + insertions * 2;

	while (insertions < pend_chain.size()) {	// Insert while there are uninserted elements in the pend chain

#ifdef DEBUG
		std::cout << indent << "Current Jacobstahl number: " << current_jacobstahl << "\n";
#endif

		if (current_jacobstahl <= main_chain.size()) {
			elements_to_insert	= current_jacobstahl - previous_jacobstahl;
			element_idx			= current_jacobstahl - 1;
		} else {
			elements_to_insert	= pend_chain.size() - previous_jacobstahl;
			element_idx			= pend_chain.size() - 1;
		}

#ifdef DEBUG
		std::cout << indent << "Inserting " << elements_to_insert << " elements" << "\n";
#endif

		size_t	count = 0;
		while (count++ < elements_to_insert) {

#ifdef DEBUG
		std::cout << indent << "Pend chain element index: " << element_idx << "\n";
		std::cout << indent << "Limiting element in main chain: " << **upper_limit << "\n";
		std::cout
				<< indent << "Limiting element in main chain index : "
				<< std::distance(main_chain.begin(), upper_limit) << "\n";
#endif

			int const	*element = pend_chain[element_idx--];
			auto		pos = std::upper_bound(main_chain.begin(), upper_limit, element,
								[](int const *val, int const *elem)
								{
									return (*val < *elem);
								});

#ifdef DEBUG
			std::cout
				<< indent << "Inserting " << *element << " before " 
				<< *(*pos) << "\n";
#endif

			main_chain.insert(pos, element);

#ifdef DEBUG
			print_chain("Partial fused chain", indent, main_chain);
#endif

			++insertions;
			upper_limit = main_chain.begin() + insertions * 2 - count;
		}

		size_t	temp = current_jacobstahl;

		current_jacobstahl += 2 * previous_jacobstahl;
		previous_jacobstahl = temp;
	}
	std::swap(source_chain, main_chain);
#ifdef DEBUG
	print_chain("Fused chain", indent, source_chain);
	std::cout << indent << R"(\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\)" << "\n";
#endif
	return source_chain;
}
