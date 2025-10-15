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

/* -------------------------------------------------------------------------- */
#ifdef DEBUG
constexpr uint8_t	RECURSION_INDENT = 8;
constexpr uint8_t	FW_02 = 35;	// Field width

static void	print_chain( std::string const &name,
				 std::string const &indent,
				 std::vector<int const *> &vec);
#endif
/* -------------------------------------------------------------------------- */

std::vector<int const *>
&vec_pointers_recursion_sort(std::vector<int const *> &source_chain)
{

#ifdef DEBUG
	static size_t	recursion_level = 0;

	++recursion_level;
	std::string	indent(recursion_level * RECURSION_INDENT, ' ');
	std::string	opening_separator(C_B_HI_Y "/////////////////////////////////////\n" C_RST);
	std::string	closing_separator(C_B_HI_G R"(\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\)""\n" C_RST);
	std::cout << indent << opening_separator;
	print_chain("Source", indent, source_chain);
#endif

	if (source_chain.size() <= 1) {
		#ifdef DEBUG
		std::cout << indent << closing_separator;
		#endif
		return source_chain;
	}

	auto	straggler	= source_chain.back();
	bool	not_even	= (source_chain.size() % 2 != 0);

	if (not_even)				// Ensure iterator lands on end() when incrementing by 2
		source_chain.pop_back();

	/**
	 * Save main elements as a vector of int pointers to the original
	 * source_chain, associate matching pend elements using an unordered map
	 * (hash map), consisting of pointer to pointer mappings
	 */
	std::vector<int const *>						main_chain;
	std::unordered_map<int const *, int const *>	pair_map;

	for (auto i = source_chain.cbegin(); i != source_chain.cend(); i += 2) {
		auto	&ptr_1 = *i;
		auto	&ptr_2 = *(i + 1);

		if (*ptr_2 < *ptr_1) {
			main_chain.push_back(ptr_1);	// Larger element goes to main
			pair_map.emplace(ptr_1, ptr_2);
		} else {
			main_chain.push_back(ptr_2);
			pair_map.emplace(ptr_2, ptr_1);
		}
	}

	#ifdef DEBUG
	std::cout << indent << std::left << std::setw(FW_02) << "Sorted pairs:";
	for (auto it = main_chain.cbegin(); it != main_chain.cend(); ++it)
		std::cout << "{" << *pair_map.at(*it) << ", " << **it << "} ";
	std::cout << "\n";
	#endif

	if (not_even)
		source_chain.push_back(straggler);

	#ifdef DEBUG
	print_chain("Main (unsorted)", indent, main_chain);
	std::cout << indent << std::left << std::setw(FW_02) << "Pend (unsorted):";
	for (auto const &e : main_chain)
		std::cout << *pair_map.at(e) << " ";
	if (not_even)
		std::cout << *straggler;
	std::cout << "\n";
	#endif

	vec_pointers_recursion_sort(main_chain);

	#ifdef DEBUG
	print_chain("Main (sorted)", indent, main_chain);
	#endif

	std::vector<int const *>	pend_chain;

	for (auto it = main_chain.cbegin(); it != main_chain.cend(); ++it)
		pend_chain.push_back(pair_map.at(*it));
	if (not_even)
		pend_chain.push_back(straggler);

	#ifdef DEBUG
	std::cout	<< indent << std::left << std::setw(FW_02)
				<< "Pend (matching main order):";
	for (auto iptr : pend_chain)
		std::cout << *iptr << " ";
	std::cout << "\n";
	#endif

	// Put b1 before a1
	main_chain.insert(main_chain.cbegin(), pend_chain.front());

	#ifdef DEBUG
	print_chain("Main with b1 inserted", indent, main_chain);
	#endif

	using It = decltype(main_chain.cbegin());
	size_t		insertions	= 1;	// b1 was already inserted
	size_t		prev_jsthal	= 1;	// b1 insertion corresponds to Jacobsthal 1
	size_t		curr_jsthal	= 3;	// 3 = 1 + 2 * 1
	size_t		pend_idx	= 0;	// pend element of element being inserted into main
	size_t		to_insert	= 0;	// How many elements to insert in a sequence
	size_t		offset		= 0;	// Element offset to find the limiting element in main (a3, a5, a11...)
	auto		comp		=	[](int const *val, int const *elem) {	// Comparison function for binary sort
									return (*val < *elem);
								};

	while (insertions < pend_chain.size()) {	// Insert while there are uninserted elements in the pend

		#ifdef DEBUG
		std::cout	<< indent << C_B_HI_W << std::left << std::setw(FW_02)
					<< "Current Jacobsthal: " << curr_jsthal << C_RST << "\n";
		#endif

		if (curr_jsthal <= pend_chain.size()) {
			to_insert	= curr_jsthal - prev_jsthal;
			pend_idx	= curr_jsthal - 1;
		} else {
			to_insert	= pend_chain.size() - prev_jsthal;
			pend_idx	= pend_chain.size() - 1;
		}

		offset = insertions + pend_idx;
		if (offset > main_chain.size())
			offset = main_chain.size();

		while (to_insert--) {
			auto element	= pend_chain[pend_idx--];
			auto begin		= main_chain.cbegin();
			auto limit		= begin + offset;
			auto pos		= std::upper_bound(begin, limit, element, comp);

			#ifdef DEBUG
			auto	ab_output_helper = [&main_chain](It const &it) {
				std::cout << "ab" << std::distance(main_chain.cbegin(), it) + 1
				<< " = " << **it << "\n"; };
			std::cout	<< indent << "Inserting b" << pend_idx + 2
						<< " = " << *element << " before ";
			if (pos >= main_chain.cend())
				std::cout << "end()\n";
			else
				ab_output_helper(pos);
			std::cout << indent << "Limiting element ";
			if (limit >= main_chain.cend())
				std::cout << "end()\n";
			else
				ab_output_helper(limit);
			#endif

			main_chain.insert(pos, element);
			++insertions;

			#ifdef DEBUG
			print_chain("Partial fused", indent, main_chain);
			#endif
		}

		size_t	temp = curr_jsthal;

		curr_jsthal += 2 * prev_jsthal;
		prev_jsthal = temp;
	}
	std::swap(source_chain, main_chain);

	#ifdef DEBUG
	print_chain("Fused", indent, source_chain);
	std::cout << indent << closing_separator;
	#endif

	return source_chain;
}
/* -------------------------------------------------------------------------- */
#ifdef DEBUG
static void	print_chain( std::string const &name,
						std::string const &indent,
						std::vector<int const *> &vec)
{
	std::cout << indent << std::left << std::setw(FW_02) << (name + ":");
	for (auto const &e : vec)
	std::cout << *e << " ";
	std::cout << std::endl;
}
#endif
