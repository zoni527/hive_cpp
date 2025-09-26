/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:51:57 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:14:46 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"
#include "ansi_colors.hpp"

std::string const	id_str				= C_B_P "Character" C_RST;
AMateria			*floor[ N_FLOOR ]	= {nullptr};
size_t				floor_idx			= 0;

// -----------------------------------------------------------------------------

void		Character:: use( int idx, ICharacter &target ) {

	if ( idx < 0 || idx >= N_MATERIA ) {
		std::cout
			<< C_B_HI_R "ERROR!" C_RST
			<< "		Character:: use: Invalid materia index: " << idx
			<< std::endl;
		return;
	} else if ( _inventory[idx] == nullptr ) {
		std::cout
			<< C_B_HI_R "ERROR!" C_RST
			<< "		Character:: use: No materia equipped at index: " << idx
			<< std::endl;
		return;
	}
	std::cout
		<< id_str << "	" << _name << " uses materia "
		<< _inventory[idx]->getType() << " on " << target.getName()
		<< std::endl;
	_inventory[idx]->use( target );
}

std::string const &Character:: getName() const {
	return _name;
}

void Character:: equip( AMateria *m ) {

	if ( m == nullptr ) {
		std::cout
			<< C_B_HI_R "ERROR!" C_RST
			<< "		Character:: equip: Materia pointer is null" << std::endl;
		return;
	}
	size_t i = -1;
	while ( ++i < N_MATERIA && _inventory[i] )
		;
	if ( i >= N_MATERIA ) {
		std::cout
			<< C_B_HI_R "ERROR!" C_RST
			<< "		Character:: equip: " << _name << "'s inventory is full" << std::endl;
		delete m;
		return;
	}
	std::cout
		<< id_str << "	" << _name << " equips materia " << m->getType()
		<< " at inventory index " << i << std::endl;
	_inventory[i] = m;
}

void Character:: unequip( int idx ) {

	if ( idx < 0 || idx >= N_MATERIA ) {
		std::cout
			<< C_B_HI_R "ERROR!" C_RST
			<< "		Character:: unequip: Invalid materia index: " << idx
			<< std::endl;
		return;
	} else if ( _inventory[idx] == nullptr ) {
		std::cout
			<< C_B_HI_R "ERROR!" C_RST
			<< "		Character:: unequip: No materia equipped at index: " << idx
			<< std::endl;
		return;
	}
	std::cout
		<< id_str << "	" << _name << " unequips materia "
		<< _inventory[idx]->getType() << " in inventory slot " << idx
		<< std::endl;
	if (floor_idx == N_FLOOR) {
		std::cout
			<< id_str << "	" << _name << " can't unequip materia "
			<< _inventory[idx]->getType() << " in inventory slot " << idx
			<< ", floor is full" << std::endl;
		return;
	}
	floor[floor_idx++] = _inventory[idx];
	_inventory[idx] = nullptr;
}

// -----------------------------------------------------------------------------

Character:: Character( std::string const &name )
: _name( name ), _inventory{} {

	std::cout	<< id_str + "	String constructor called with parameter: "
				<< name << std::endl;
}

Character:: Character( Character const &src )
: _name( src._name ), _inventory{} {

	std::cout << id_str + "	Copy constructor called" << std::endl;

	for ( size_t i = 0; i < N_MATERIA && src._inventory[i] != nullptr; ++i )
		_inventory[i] = src._inventory[i]->clone();
}

// -----------------------------------------------------------------------------

Character::~Character() {

	std::cout << id_str + "	Destructor called" << std::endl;
	for ( auto p : _inventory )
		delete p;
}

// -----------------------------------------------------------------------------

Character &Character:: operator = ( Character const &src ) {

	std::cout << id_str + "	Copy assignment operator called" << std::endl;

	if ( this != &src ) {
		_name = src._name;
		for ( auto *p : _inventory ) {
			if ( p == nullptr )
				break;
			delete p;
			p = nullptr;
		}
		for ( size_t i = 0; i < N_MATERIA && src._inventory[i]; ++i )
			_inventory[i] = src._inventory[i]->clone();
	}
	return *this;
}
