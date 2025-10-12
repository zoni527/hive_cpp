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

#include <vector>
#include "PmergeMe.hpp"

int	main()
{
	std::vector<int>	numbers = {7, 3, 6, 4, 1, 2, 5, 9, 8, 9, 1};

	merge_insertion_sort_vec<std::vector<int>>(numbers);
	return 0;
}
