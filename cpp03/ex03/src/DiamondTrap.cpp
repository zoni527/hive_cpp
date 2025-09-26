/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:24:41 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/11 11:31:37 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ansi_colors.hpp"
#include <iostream>

const std::string	diamond_trap_str = C_B_Y "DiamondTrap" C_RST;
const std::string	clap_trap_str = C_B_P "ClapTrap" C_RST;

// ------------------------------------------------------------ member functions

void DiamondTrap:: attack( std::string const &target ) {
	ScavTrap:: attack( target );
}

void DiamondTrap:: whoAmI() {
	std::cout
		<< "My " + diamond_trap_str + " name is " + _name << "" << std::endl
		<< "My " + clap_trap_str + " name is " + ClapTrap:: _name << std::endl;
}

// ---------------------------------------------------------------- constructors

DiamondTrap:: DiamondTrap()
: ClapTrap( C_B_HI_P "sane_default_clap_name" C_RST ) {

	std::cout << diamond_trap_str << "	default constructor called" << std::endl;
	_name			= C_B_HI_Y "sane_default" C_RST;
	_hp	= _max_hp	= FRAGTRAP_HP;
	_ep	= _max_ep	= SCAVTRAP_EP;
	_ad				= FRAGTRAP_AD;
}

DiamondTrap:: DiamondTrap( std::string const &name )
: ClapTrap( C_B_HI_P + name + "_clap_name" + C_RST ) {

	std::cout << diamond_trap_str << "	string constructor called" << std::endl;
	_name			= C_B_HI_Y + name + C_RST;
	_hp	= _max_hp	= FRAGTRAP_HP;
	_ep	= _max_ep	= SCAVTRAP_EP;
	_ad				= FRAGTRAP_AD;
}

DiamondTrap:: DiamondTrap( DiamondTrap const &src )
: ClapTrap( src._name + C_B_HI_P "_clap_name" + C_RST ), ScavTrap(), FragTrap() {

	std::cout << diamond_trap_str << "	copy constructor called" << std::endl;
	_name	= src._name;
	_max_hp	= FRAGTRAP_HP;
	_max_ep	= SCAVTRAP_EP;
	_ad		= FRAGTRAP_AD;
	_hp		= ( src._hp > _max_hp ? _max_hp : src._hp );
	_ep 	= ( src._ep > _max_ep ? _max_ep : src._ep );
}

// ------------------------------------------------------------------ destructor

DiamondTrap:: ~DiamondTrap() {

	std::cout << diamond_trap_str + "	destructor called" << std::endl;
}

// --------------------------------------------------- member operator overloads

DiamondTrap &DiamondTrap:: operator = ( DiamondTrap const &src ) {

	std::cout << diamond_trap_str + "	assignment operator called" << std::endl;
	if ( this != &src ) {
		ClapTrap:: _name = src.ClapTrap::_name;
		_name	= src._name;
		_max_hp	= FRAGTRAP_HP;
		_max_ep	= SCAVTRAP_EP;
		_ad		= FRAGTRAP_AD;
		_hp		= ( src._hp > _max_hp ? _max_hp : src._hp );
		_ep 	= ( src._ep > _max_ep ? _max_ep : src._ep );
	}
	return *this;
}
