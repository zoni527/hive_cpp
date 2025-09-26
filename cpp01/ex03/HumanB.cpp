/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:51:49 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/02 16:08:11 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

// ------------------------------------------------------------ member functions

void HumanB:: attack() {

	std::cout	<< _name << " attacks with their ";
	if (!_weapon)
		std::cout << "bare hands";
	else
		std::cout << _weapon->getType();
	std::cout << std::endl;
}

void HumanB:: setWeapon( Weapon const &weapon ) {
	this->_weapon = &weapon;
	std::cout << _name << " has equipped " << _weapon->getType() << std::endl;
}

// ----------------------------------------------------------------- constructor

HumanB:: HumanB( std::string const &str) :
	_name(str) {
	std::cout << _name << " has entered the battlefield" << std::endl;
}

// ------------------------------------------------------------------ destructor

HumanB::~HumanB() {
	std::cout << _name << " has left the battlefield" << std::endl;
}
