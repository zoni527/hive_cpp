/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:57:54 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/02 16:08:31 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie *newZombie( std::string name ) {
	std::cout << "Creating new Zombie" <<std::endl;
	return (new Zombie(name));
}
