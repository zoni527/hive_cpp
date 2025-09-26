/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:49:59 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:14:39 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "ansi_colors.hpp"

std::string const	id_str = C_B_HI_W "AMateria" C_RST;

// -----------------------------------------------------------------------------

std::string const &AMateria::getType() const {

	return _type;
}

void AMateria:: use( ICharacter &target ) {

	std::cout
		<< "* uses materia of type " << _type << " on " << target.getName()
		<< std::endl;
}

// -----------------------------------------------------------------------------

AMateria:: AMateria( std::string const &type )
: _type( type ) {

	std::cout	<< id_str << "	String constructor called with parameter: "
				<< type << std::endl;
}

AMateria:: ~AMateria() {

	std::cout << id_str << "	Destructor called" << std::endl;
}
