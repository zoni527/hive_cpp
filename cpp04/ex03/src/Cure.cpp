/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:01:02 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:14:53 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ansi_colors.hpp"
#include <iostream>

std::string const	id_str = C_B_HI_G "Cure" C_RST;

// -----------------------------------------------------------------------------

Cure *Cure:: clone() const {

	return new Cure();
}

void Cure:: use( ICharacter &target ) {

	std::string output = C_HI_G "* heals " C_RST;
	output += target.getName() + C_HI_G + "'s wounds *" + C_RST;
	std::cout << output << std::endl;
}

// -----------------------------------------------------------------------------

Cure:: Cure()
: AMateria( "cure" ) {

	std::cout << id_str << "		Default constructor called" << std::endl;
}

Cure:: ~Cure() {

	std::cout << id_str << "		Destructor called" << std::endl;
}
