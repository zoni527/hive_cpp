/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:27:07 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/02 16:09:12 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

// ------------------------------------------------------------ member functions

std::string const &Weapon:: getType() const {
	return _type;
}

void Weapon::setType( std::string const &str ) {
	_type = str;
}

// ----------------------------------------------------------------- constructor

Weapon:: Weapon( std::string const &str ) :
	_type(str) {
	std::cout << "A " << _type << " has spawned in" << std::endl;
}

// ------------------------------------------------------------------ destructor

Weapon:: ~Weapon () {
	std::cout << "A " << _type << " has despawned" << std::endl;
}
