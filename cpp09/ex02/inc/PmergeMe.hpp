/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:34:56 by jvarila           #+#    #+#             */
/*   Updated: 2025/10/07 18:15:11 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <unordered_map>

#define DEBUG

template<class T>
void	print_container(T const &container, std::string const &indent)
{
	std::cout << indent;
	for (auto const &e : container)
		std::cout << e << " ";
	std::cout << indent << std::endl;
}

template<class T, class U>
void	merge_insertion_sort(T &container)
{
	if (container.size() < 2)
		return;

	#ifdef DEBUG
	static size_t	recursion_level = 0;

	++recursion_level;
	std::string	indent((recursion_level - 1) * 3, ' ');
	std::cout << indent << "* ------------------------------------------------ *\n";
	std::cout << indent << "Recursion level: " << recursion_level << "\n";
	std::cout << indent << "Original chain\n";
	print_container(container, indent);
	#endif

	int		leftover	= -1;
	bool	odd			= (container.size() % 2 != 0);
	if (odd)
	{
		leftover = container.back();
		container.pop_back();
	}

	U										main_chain;
	U										pend_chain;
	std::unordered_map< size_t, size_t >	pairs;
	size_t									count = 0;
	for (auto i = container.begin(); i != container.end(); i += 2)
	{
		if (*(i + 1) < *i)
			std::swap(*(i + 1), *i);
		main_chain.push_back(*(i + 1));
		pend_chain.push_back(*i);
		pairs.emplace(main_chain.end() - 1, pend_chain.end() - 1);
	}
	if (odd)
	{
		pend_chain.push_back(leftover);
		container.push_back(leftover);
	}
	if (container.size() <= 2)
	{
		#ifdef DEBUG
		--recursion_level;
		#endif
		return;
	}

	#ifdef DEBUG
	std::cout << indent << "Original chain (with ordered pairs)\n";
	print_container(container, indent);
	std::cout << indent << "Main chain\n";
	print_container(main_chain, indent);
	std::cout << indent << "Side chain\n";
	print_container(pend_chain, indent);
	std::cout << indent << "Pairs and indices: ";
	for (auto &e : pairs)
	  std::cout << *e.first << " " << *e.second << "  ";
	std::cout << "\n";
	#endif
	merge_insertion_sort<T, U>(main_chain);
	#ifdef DEBUG
	std::cout << indent << "Recursion level: " << recursion_level << "\n";
	--recursion_level;
	#endif

	U	fused_chain(main_chain);
	fused_chain.insert(fused_chain.begin(), pend_chain[pairs[main_chain.begin()]]);

	size_t	insertions			= 1;
	size_t	previous_jacobstahl	= 1;
	size_t	current_jacobstahl	= 3;
	while (insertions < pend_chain.size())
	{
		decltype(fused_chain.begin())	upper_limit;
		size_t							insertable_idx;
		size_t							elements_to_insert;
		if (current_jacobstahl <= main_chain.size())
		{
			insertable_idx		= current_jacobstahl - 1;
			elements_to_insert	= current_jacobstahl - previous_jacobstahl;
			upper_limit			= &fused_chain[insertable_idx + insertions];
		}
		else
		{
			insertable_idx		= main_chain.size();
			elements_to_insert	= main_chain.size() - previous_jacobstahl;
			upper_limit			= fused_chain.end();
		}

		while (elements_to_insert--)
		{
			int		insertable = pairs[main_chain[insertable_idx--]];
			auto	pos = std::lower_bound(upper_limit--, insertable);
			fused_chain.insert(pos, insertable);
		}
	}
	std::swap(main_chain, fused_chain);

	#ifdef DEBUG
	std::cout << "Sorted main chain: \n";
	print_container(main_chain);
	#endif
}
