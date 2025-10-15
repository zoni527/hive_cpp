/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:40:48 by jvarila           #+#    #+#             */
/*   Updated: 2025/10/15 17:21:58 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <list>
#include <sstream>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	std::list<int>	numbers;
	std::string		word;
	int				num;

	if (isatty(STDIN_FILENO)) {
		if (argc < 2) {
			std::cout << "Usage: ./PmergeMe <list of positive integers>\n";
			return 0;
		}
		for (int i = 1; i < argc; ++i) {
			std::stringstream	input(argv[i]);

			while (input >> word) {
				std::stringstream	word_to_num(word);

				if (!(word_to_num >> num) || num < 1) {
					std::cerr << "Error" << std::endl;
					return 1;
				}
				numbers.push_back(num);
			}
		}
	} else {

		while (std::cin >> word) {
			std::stringstream	word_to_num(word);

			if (word_to_num >> num)
				numbers.push_back(num);
		}
	}

	merge_insertion_sort_vec<std::list<int>>(numbers);

	return 0;
}
