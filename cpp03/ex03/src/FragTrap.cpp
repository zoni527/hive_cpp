/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:10:04 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/10 13:12:58 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ansi_colors.hpp"
#include <iostream>

const std::string	frag_trap_str = C_B_R "FragTrap" C_RST;

// ------------------------------------------------------------ member functions

void	FragTrap:: attack( std::string const &target ) {

	std::string reason = "";
	if ( _hp == 0 )
		reason = "is KO";
	else if ( _ep == 0 )
		reason = "is out of energy";
	if ( !reason.empty() ) {
		std::cout
			<< frag_trap_str + "	" << _name << " " << reason
			<< ", can't attack " << target << std::endl;
		return;
	}
	--_ep;
	std::cout
		<< frag_trap_str + "	" << _name << " attacks " << target
		<< ", causing " << _ad << " points of damage! It now has "
		<< _ep << " energy points left" << std::endl;
}

void	FragTrap:: highFivesGuys() {

	std::cout
		<< frag_trap_str + "	" << _name << " sends you a positive high fives request"
		<< std::endl;
}

// ---------------------------------------------------------------- constructors

FragTrap:: FragTrap()
: ClapTrap( C_B_HI_R "sane_default" C_RST ) {

	std::cout << frag_trap_str << "	default constructor called" << std::endl;
	_hp	= _max_hp	= FRAGTRAP_HP;
	_ep	= _max_ep	= FRAGTRAP_EP;
	_ad				= FRAGTRAP_AD;
}

FragTrap:: FragTrap( std::string const &name )
: ClapTrap( C_B_HI_R + name + C_RST ) {

	std::cout << frag_trap_str << "	string constructor called" << std::endl;
	_hp	= _max_hp	= FRAGTRAP_HP;
	_ep	= _max_ep	= FRAGTRAP_EP;
	_ad				= FRAGTRAP_AD;

}

FragTrap:: FragTrap( FragTrap const &src )
: ClapTrap( src._name ) {

	std::cout << frag_trap_str << "	copy constructor called" << std::endl;
	_max_hp	= FRAGTRAP_HP;
	_max_ep	= FRAGTRAP_EP;
	_ad		= FRAGTRAP_AD;
	_hp		= ( src._hp > _max_hp ? _max_hp : src._hp );
	_ep 	= ( src._ep > _max_ep ? _max_ep : src._ep );
}

// ------------------------------------------------------------------ destructor

FragTrap:: ~FragTrap() {

	std::cout << frag_trap_str << "	destructor called" << std::endl;
}

// --------------------------------------------------- member operator overloads

FragTrap &FragTrap:: operator = ( FragTrap const &src ) {

	std::cout << frag_trap_str << "	assignment operator called" << std::endl;
	if ( this != &src ) {
		_name	= src._name;
		_max_hp	= FRAGTRAP_HP;
		_max_ep	= FRAGTRAP_EP;
		_ad		= FRAGTRAP_AD;
		_hp		= ( src._hp > _max_hp ? _max_hp : src._hp );
		_ep 	= ( src._ep > _max_ep ? _max_ep : src._ep );
	}
	return *this;
}
