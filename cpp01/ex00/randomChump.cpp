/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:02:14 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/02 16:08:35 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void randomChump( std::string name ) {
	std::cout << "Spawning random chump\n";
	Zombie random(name);
	random.announce();
}
