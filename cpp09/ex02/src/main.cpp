/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:40:48 by jvarila           #+#    #+#             */
/*   Updated: 2025/10/07 17:38:17 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdint>
#include <vector>
#include <list>
#include <sstream>

int	main(int argc, char *argv[])
{
	std::vector<int>	numbers = {7, 3, 6, 4, 1, 2, 5, 9, 8, 9, 1};
	std::list<int>		nums;

	if (argc < 2) {
		std::cout << "Usage: ./PmergeMe <list of numbers>\n";
		return 0;
	}

	for (int i = 1; i < argc; ++i) {
		std::stringstream	input(argv[i]);
		std::string			word;
		int					num;

		while (input >> word) {
			std::stringstream	to_num(word);

			if (to_num >> num)
				nums.push_back(num);
		}
	}
	if (nums.size() == 0)
	{
		std::cerr << "ERROR: bad input" << std::endl;
		return 1;
	}
	merge_insertion_sort_vec<std::list<int>>(nums);
	return 0;
}
