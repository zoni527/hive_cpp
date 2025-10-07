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
	U										main_chain;
	U										side_chain;
	bool									odd;
	std::unordered_multimap<int, size_t>	pairs;
	int										leftover	= 0;
	size_t									count		= 0;

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
	odd = (container.size() % 2 != 0);
	if (odd)
	{
		leftover = container.back();
		container.pop_back();
	}
	for (auto i = container.begin(); i != container.end(); i += 2)
	{
		if (*(i + 1) < *i)
			std::swap(*(i + 1), *i);
		main_chain.push_back(*(i + 1));
		side_chain.push_back(*i);
		pairs.emplace(*(i + 1), count++);
	}
	if (odd)
	{
		side_chain.push_back(leftover);
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
	print_container(side_chain, indent);
	std::cout << indent << "Pairs and indices: ";
	for (auto &e : pairs)
	  std::cout << e.first << " " << e.second << "  ";
	std::cout << "\n";
	#endif
	merge_insertion_sort<T, U>(main_chain);
	#ifdef DEBUG
	std::cout << indent << "Recursion level: " << recursion_level << "\n";
	--recursion_level;
	#endif
}
