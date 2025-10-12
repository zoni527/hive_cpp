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
#include <utility>
#include <unordered_map>

#define DEBUG

template<class T>
void	print_container(T const &container, std::string const &indent);

template<class T>
void	print_pairs_vec(std::vector< std::pair<T, T> > &pairs);

template<class T>
auto	vec_pairs_recursion(
	std::vector< std::pair<T, T> > &pairs);

template<class T>
void	merge_insertion_sort_vec(T &container)
{
	if (container.size() < 2)
		return;

#ifdef DEBUG
	std::cout << "Source chain\n";
	print_container(container, "");
#endif

	auto	straggler	= container.back();
	bool	not_even	= (container.size() % 2 != 0);

	if (not_even)				// Ensure iterator lands on end() when incrementing by 2
		container.pop_back();

	using It = decltype(container.begin());

	std::vector<std::pair<It, It>>	pairs;

	std::unordered_map<uintptr_t, uintptr_t>	pair_map;

	std::unordered_map<int *, int *>	test;
	(void)test;
	int	itest = 2;
	test.emplace(&(*container.begin()), &itest);

	using Ptr = decltype(&(*container.begin()));

	std::vector<Ptr>	main;

	for (auto i = container.begin(); i != container.end(); i += 2)
	{
		auto	iter_1	= i;
		auto	iter_2	= i + 1;
		auto	&elem_1 = *iter_1;
		auto	&elem_2	= *iter_2;

		if (elem_2 < elem_1) {
			pairs.emplace_back(iter_2, iter_1);			// 0 -> small, 1 -> big
			main.push_back(&elem_1);
			pair_map.emplace(
				reinterpret_cast<uintptr_t>(&elem_1),	// main chain element -> pend chain element
				reinterpret_cast<uintptr_t>(&elem_2));
		} else {
			pairs.emplace_back(iter_1, iter_2);
			main.push_back(&elem_2);
			pair_map.emplace(
				reinterpret_cast<uintptr_t>(&elem_2),
				reinterpret_cast<uintptr_t>(&elem_1));
		}
	}

	if (not_even)
		container.push_back(straggler);

#ifdef DEBUG
	std::cout << "Pairs:\n";
	print_pairs_vec(pairs);
	std::cout << "\n";

	std::cout << "Main chain:\n";
	for (auto ptr : main) {
		std::cout << *ptr << " ";
	}
	std::cout << "\n";

	std::cout << "Pend chain:\n";
	for (auto main_ptr : main) {

		auto pend_ptr_num	= pair_map[reinterpret_cast<uintptr_t>(main_ptr)];
		auto pend_ptr		= reinterpret_cast<int *>(pend_ptr_num);

		std::cout << *pend_ptr << " ";
	}
	std::cout << "\n";
#endif

	// vec_pairs_recursion(pairs);
	//U	fused_chain(main_chain);
	//fused_chain.insert(fused_chain.begin(), pend_chain[pairs[main_chain.begin()]]);

	//size_t	insertions			= 1;
	//size_t	previous_jacobstahl	= 1;
	//size_t	current_jacobstahl	= 3;
	//while (insertions < pend_chain.size())
	//{
	//	decltype(fused_chain.begin())	upper_limit;
	//	size_t							insertable_idx;
	//	size_t							elements_to_insert;
	//	if (current_jacobstahl <= main_chain.size())
	//	{
	//		insertable_idx		= current_jacobstahl - 1;
	//		elements_to_insert	= current_jacobstahl - previous_jacobstahl;
	//		upper_limit			= &fused_chain[insertable_idx + insertions];
	//	}
	//	else
	//	{
	//		insertable_idx		= main_chain.size();
	//		elements_to_insert	= main_chain.size() - previous_jacobstahl;
	//		upper_limit			= fused_chain.end();
	//	}

	//	while (elements_to_insert--)
	//	{
	//		int		insertable = pairs[main_chain[insertable_idx--]];
	//		auto	pos = std::lower_bound(upper_limit--, insertable);
	//		fused_chain.insert(pos, insertable);
	//	}
	//}
	//std::swap(main_chain, fused_chain);

	//#ifdef DEBUG
	//std::cout << "Sorted main chain: \n";
	//print_container(main_chain);
	//#endif
}

template<class T>
auto	vec_pairs_recursion(
	std::vector< std::pair<T, T> > &pairs)
{
	if (pairs.size() <= 1)
		return pairs;

#ifdef DEBUG
	static size_t		recursion_level = 0;
	std::string			indent(1 + recursion_level * 2, ' ');
	std::vector< int >	main;
	std::vector< int >	pend;

	for (auto const &e : pairs)
	{
		main.emplace_back(*std::get<1>(e));
		pend.emplace_back(*std::get<0>(e));
	}
	std::cout << indent << "///////////////////////////////\n";
	std::cout << indent << "Pairs:\n";
	std::cout << indent;
	print_pairs_vec(pairs);
	std::cout << indent << "Main:\n";
	print_container(main, indent);
	std::cout << indent << "Pend:\n";
	print_container(pend, indent);
	++recursion_level;
#endif

	auto	straggler	= pairs.back();
	bool	not_even	= (pairs.size() % 2 != 0);

	if (not_even)
		pairs.pop_back();

	std::vector< std::pair<T, T> >	new_main;

	for (auto i = pairs.begin(); i != pairs.end(); i += 2)
	{
		auto iter_1 = std::get<1>(*i);
		auto iter_2 = std::get<1>(*(i + 1));
		if (*iter_2 < *iter_1)
			new_main.emplace_back(iter_2, iter_1);
		else
			new_main.emplace_back(iter_1, iter_2);
	}
	std::cout << std::endl;

	if (not_even)
		pairs.push_back(straggler);

	return vec_pairs_recursion(new_main);
}

template<class T>
void	print_container(T const &container, std::string const &indent)
{
	std::cout << indent;
	for (auto const &e : container)
		std::cout << e << " ";
	std::cout << indent << std::endl;
}

template<class T>
void	print_pairs_vec(std::vector< std::pair<T, T> > &pairs)
{
	for (auto const &e : pairs)
	{
		auto first	= std::get<0>(e);
		auto second	= std::get<1>(e);
		std::cout << "{" << *first << ", " << *second << "} ";
	}
	std::cout << std::endl;
}
