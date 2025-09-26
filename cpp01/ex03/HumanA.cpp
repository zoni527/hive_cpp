/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:31:25 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/02 16:08:53 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

// ------------------------------------------------------------ member functions

void HumanA:: attack() {
	std::cout	<< _name << " attacks with their "
				<< _weapon.getType() << std::endl;
}

// ----------------------------------------------------------------- constructor

HumanA:: HumanA( std::string const &str, Weapon const &weapon) :
	_name(str), _weapon(weapon) {
	std::cout << _name << " has entered the battlefield" << std::endl;
}

// ------------------------------------------------------------------ destructor

HumanA::~HumanA() {
	std::cout << _name << " has left the battlefield" << std::endl;
}
