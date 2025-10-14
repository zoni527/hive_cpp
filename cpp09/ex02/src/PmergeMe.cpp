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
#include <cinttypes>
#include <iomanip>

/* -------------------------------------------------------------------------- */

constexpr uint8_t	RECURSION_OFFSET = 5;
constexpr uint8_t	TEXT_WIDTH = 35;

static void	print_chain( std::string const &name,
				 std::string const &indent,
				 std::vector<int const *> vec);

/* -------------------------------------------------------------------------- */

std::vector<int const *>
&vec_pointers_recursion_sort(std::vector<int const *> &source_chain)
{
#ifdef DEBUG
	static size_t	recursion_level = 0;

	++recursion_level;
	std::string	indent(recursion_level * RECURSION_OFFSET, ' ');
	std::string	opening_separator(C_B_HI_Y "//////////////////////////////////\n" C_RST);
	std::string	closing_separator(C_B_HI_G R"(\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\)" C_RST);
	std::cout << indent << opening_separator;
	print_chain("Source chain", indent, source_chain);
#endif

	if (source_chain.size() <= 1) {
#ifdef DEBUG
		std::cout << indent << closing_separator << "\n";
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
	std::cout << indent << "Pend chain (unsorted):\n" << indent;
	for (auto const &e : main_chain)
		std::cout << *pair_map[e] << " ";
	if (not_even)
		std::cout << *straggler;
	std::cout << "\n";
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
	std::cout
		<< indent << std::left << std::setw(TEXT_WIDTH)
		<< "Pend chain (matching main order):";
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
	size_t		insertions			= 1;		// b1 was already inserted
	size_t		previous_jacobstahl	= 1;		// b1 insertion corresponds to Jacobstahl 1
	size_t		current_jacobstahl	= 3;
	size_t		pend_idx			= 0;		// pend chain element of element being inserted into main
	size_t		elements_to_insert	= 0;		// How many elements to insert in a sequence
	size_t		offset				= 0;		// Element offset to find the limiting element in main (b3, b5, b11...)
	It			upper_limit			= main_chain.begin();	// Iterator to limiting element
	It			pos					= main_chain.begin();	// Position for insertion
	int const	*element			= nullptr;				// Helper to get element from pend

	while (insertions < pend_chain.size()) {	// Insert while there are uninserted elements in the pend chain

#ifdef DEBUG
		std::cout << indent << "Current Jacobstahl number: " << current_jacobstahl << "\n";
#endif

		if (current_jacobstahl <= main_chain.size()) {
			elements_to_insert	= current_jacobstahl - previous_jacobstahl;
			pend_idx			= current_jacobstahl - 1;
		} else {
			elements_to_insert	= pend_chain.size() - previous_jacobstahl;
			pend_idx			= pend_chain.size() - 1;
		}

		offset = insertions + pend_idx;
		if (offset >= main_chain.size())
			offset = main_chain.size() - 1;
		upper_limit = main_chain.begin() + offset;
		std::cout << "Offset : " << offset << "\n";

		size_t	count = 0;
		while (count++ < elements_to_insert) {

#ifdef DEBUG
		std::cout << indent
				<< "Limiting element in main chain:	Index: "
				<< std::distance(main_chain.begin(), upper_limit)
				<< "	Value: " << **upper_limit << "\n";
#endif

			element		= pend_chain[pend_idx--];
			pos = std::upper_bound(main_chain.begin(), upper_limit, element,
							[](int const *val, int const *elem)
							{
								return (*val < *elem);
							});

#ifdef DEBUG
			std::cout
				<< indent << "Inserting b" << pend_idx + 2
				<< " = " << *element << "\n";
#endif

			main_chain.insert(pos, element);

#ifdef DEBUG
			print_chain("Partial fused chain", indent, main_chain);
#endif

			++insertions;
			// insertions * 2 -> inserted b1 and b2 -> skip b1, b2, a1 and a2 -> land on a3
			upper_limit = main_chain.begin() + offset;
		}

		size_t	temp = current_jacobstahl;

		current_jacobstahl += 2 * previous_jacobstahl;
		previous_jacobstahl = temp;
	}
	std::swap(source_chain, main_chain);
#ifdef DEBUG
	print_chain("Fused chain", indent, source_chain);
	std::cout << indent << closing_separator << "\n";
#endif
	return source_chain;
}

static void	print_chain( std::string const &name,
						std::string const &indent,
						std::vector<int const *> vec)
{
	std::cout << indent << std::left << std::setw(TEXT_WIDTH) << (name + ":");
	for (auto const &e : vec)
	std::cout << *e << " ";
	std::cout << std::endl;
}
