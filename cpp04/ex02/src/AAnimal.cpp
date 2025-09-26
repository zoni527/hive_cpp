/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:12:32 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 17:00:12 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "ansi_colors.hpp"
#include <iostream>

std::string const	animal_str = C_B_HI_W "AAnimal" C_RST;

// ------------------------------------------------------------ member functions

std::string AAnimal:: getType() const {

	return _type;
}

// ---------------------------------------------------------------- constructors

AAnimal:: AAnimal() : _type( "AAnimal" ) {

	std::cout << animal_str + "	Default constructor called" << std::endl;
}

AAnimal:: AAnimal( AAnimal const &src ) {

	std::cout << animal_str + "	Copy constructor called" << std::endl;
	_type = src._type;
}

// ------------------------------------------------------------------ destructor

AAnimal:: ~AAnimal() {

	std::cout << animal_str + "	Destructor called" << std::endl;
}

// ---------------------------------------------------------- operator overloads

AAnimal &AAnimal:: operator = ( AAnimal const &src ) {

	std::cout << animal_str + "	Copy assignment operator called" << std::endl;
	if (this == &src)
		return *this;
	_type = src._type;
	return *this;
}
