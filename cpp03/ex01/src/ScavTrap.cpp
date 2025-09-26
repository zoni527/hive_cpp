/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:01:05 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/10 11:14:34 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ansi_colors.hpp"
#include <iostream>

const std::string	scav_trap_str = C_B_C "ScavTrap" C_RST;

// ------------------------------------------------------------ member functions

void	ScavTrap:: attack( std::string const &target ) {

	std::string reason = "";
	if ( _hp == 0 )
		reason = "is KO";
	else if ( _ep == 0 )
		reason = "is out of energy";
	if ( !reason.empty() ) {
		std::cout
			<< scav_trap_str + "	" << _name << " " << reason
			<< ", can't attack " << target << std::endl;
		return;
	}
	--_ep;
	std::cout
		<< scav_trap_str + "	" << _name << " attacks " << target
		<< ", causing " << _ad << " points of damage! It now has "
		<< _ep << " energy points left" << std::endl;
}

void	ScavTrap:: guardGate() {

	std::cout
		<< scav_trap_str + "	" << _name << " is now in Gate keeper mode" << std::endl;
}

// ---------------------------------------------------------------- constructors

ScavTrap:: ScavTrap()
: ClapTrap( C_B_HI_C "sane_default" C_RST ) {

	std::cout << scav_trap_str + "	default constructor called" << std::endl;
	_hp	= _max_hp	= SCAVTRAP_HP;
	_ep	= _max_ep	= SCAVTRAP_EP;
	_ad				= SCAVTRAP_AD;
}

ScavTrap:: ScavTrap( std::string const &name )
: ClapTrap( C_B_HI_C + name + C_RST ) {

	std::cout << scav_trap_str + "	string constructor called" << std::endl;
	_hp	= _max_hp	= SCAVTRAP_HP;
	_ep	= _max_ep	= SCAVTRAP_EP;
	_ad				= SCAVTRAP_AD;
}

ScavTrap:: ScavTrap( ScavTrap const &src )
: ClapTrap( src._name ) {

	std::cout << scav_trap_str + "	copy constructor called" << std::endl;
	_max_hp	= SCAVTRAP_HP;
	_max_ep	= SCAVTRAP_EP;
	_ad		= SCAVTRAP_AD;
	_hp		= ( src._hp > _max_hp ? _max_hp : src._hp );
	_ep 	= ( src._ep > _max_ep ? _max_ep : src._ep );
}

// ------------------------------------------------------------------ destructor

ScavTrap:: ~ScavTrap() {

	std::cout << scav_trap_str + "	destructor called" << std::endl;
}

// --------------------------------------------------- member operator overloads

ScavTrap &ScavTrap:: operator = ( ScavTrap const &src ) {

	std::cout << scav_trap_str + "	assignment operator called" << std::endl;
	if ( this != &src ) {
		_name	= src._name;
		_max_hp	= SCAVTRAP_HP;
		_max_ep	= SCAVTRAP_EP;
		_ad		= SCAVTRAP_AD;
		_hp		= ( src._hp > _max_hp ? _max_hp : src._hp );
		_ep 	= ( src._ep > _max_ep ? _max_ep : src._ep );
	}
	return *this;
}
