/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:11:57 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:14:48 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "ansi_colors.hpp"
#include <iostream>

std::string const id_str = C_B_HI_Y "MateriaSource" C_RST;

// -----------------------------------------------------------------------------

/**
 * This function will free the pointer that is given to it, because the
 * subject's main would leak otherwise. This does create a risk for programmer
 * error, if the programmer assumes that the learned materia is still accessible.
 * (although it isn't marked const, so I guess all bets are off then)
 */
void MateriaSource:: learnMateria( AMateria *materia ) {

	if ( _learned[ N_SOURCEMATERIA - 1 ] != nullptr ) {
		std::cout << id_str << "	Materia slots are full" << std::endl;
		return;
	}
	for ( size_t i = 0; i < N_SOURCEMATERIA; ++i ) {
		if ( _learned[i] != nullptr )
			continue;
		_learned[i] = materia->clone();
		delete materia;
		std::cout
			<< id_str << "	Learned materia: " << _learned[i]->getType()
			<< std::endl;
		break;
	}
}

AMateria *MateriaSource:: createMateria( std::string const &type ) {

	for ( size_t i = 0; i < N_SOURCEMATERIA && _learned[i] != nullptr; ++i )
		if ( _learned[i]->getType() == type ) {
			std::cout
				<< id_str << "	Creating materia:" << type
				<< std::endl;
			return _learned[i]->clone();
		}
	return 0;
}

// -----------------------------------------------------------------------------

MateriaSource:: MateriaSource()
: _learned{} {

	std::cout << id_str << "	Default constructor called" << std::endl;
}

MateriaSource:: MateriaSource( MateriaSource const &src )
: _learned{} {

	std::cout << id_str << "	Copy constructor called" << std::endl;
	for ( size_t i = 0; i < N_SOURCEMATERIA && src._learned[i]; ++i )
		_learned[i] = src._learned[i]->clone();
}

// -----------------------------------------------------------------------------

MateriaSource:: ~MateriaSource() {

	std::cout << id_str << "	Destructor called" << std::endl;
	for ( auto p = std::begin( _learned ); p != std::end( _learned ) && *p != nullptr; ++p )
		delete *p;
}

// -----------------------------------------------------------------------------

MateriaSource &MateriaSource:: operator = ( MateriaSource const &src ) {

	if ( this != &src ) {
		for ( AMateria *p : _learned ) {
			if ( p == nullptr )
				break;
			delete p;
			p = nullptr;
		}
		for ( size_t i = 0; i < N_SOURCEMATERIA && src._learned[i]; ++i )
			_learned[i] = src._learned[i]->clone();
	}
	return *this;
}
