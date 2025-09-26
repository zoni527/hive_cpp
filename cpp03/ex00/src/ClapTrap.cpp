/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:13:23 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/10 11:18:50 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ansi_colors.hpp"
#include <iostream>

const std::string	clap_trap_str = C_B_P "ClapTrap" C_RST;

// ------------------------------------------------------------ member functions

std::string ClapTrap:: getName() const {			// getters
	return _name;
}

unsigned int ClapTrap:: getHP() const {
	return _hp;
}

unsigned int ClapTrap:: getEP() const {
	return _ep;
}

unsigned int ClapTrap:: getAD() const {
	return _ad;
}

void ClapTrap:: setName( std::string const &str ) {		// setters
	_name = str;
}

void ClapTrap:: setHP( unsigned int hp ) {
	_hp = hp;
}

void ClapTrap:: setEP( unsigned int ep ) {
	_ep = ep;
}

void ClapTrap:: setAD( unsigned int ad ) {
	_ep = ad;
}

void ClapTrap:: attack( std::string const &target ) {

	std::string reason = "";
	if ( _hp == 0 )
		reason = "is KO";
	else if ( _ep == 0 )
		reason = "is out of energy";
	if ( !reason.empty() ) {
		std::cout
			<< clap_trap_str + "	" << _name << " " << reason
			<< ", can't attack " << target << std::endl;
		return;
	}
	--_ep;
	std::cout
		<< clap_trap_str + "	" << _name << " attacks " << target
		<< ", causing " << _ad << " points of damage! It now has "
		<< _ep << " energy points left" << std::endl;
}

void ClapTrap:: takeDamage( unsigned int amount ) {

	std::string state;
	if ( _hp == 0 )
		state = "is still KO (good job beating a dead horse)";
	else if ( amount >= _hp ) {
		_hp = 0;
		state = "is now KO";
	}
	else {
		_hp -= amount;
		state = "now has " + std::to_string(_hp) + " hit points left";
	}
	std::cout
		<< clap_trap_str << "	" << _name << " has taken " << amount
		<< " points of damage and " << state << std::endl;
}

void ClapTrap:: beRepaired( unsigned int amount ) {

	if ( _ep == 0 ) {
		std::cout
			<< clap_trap_str + "	" << _name
			<< " has no energy left, can't repair itself" << std::endl;
		return;
	}
	--_ep;
	if ( amount >= CLAPTRAP_HP - _hp )
		_hp = CLAPTRAP_HP;
	else
		_hp += amount;
	std::cout
		<< clap_trap_str + "	" << _name << " repaired itself by " << amount
		<< " hit points and now has " << _hp << " hit points and "
		<< _ep << " energy points left" << std::endl;
}

// ---------------------------------------------------------------- constructors

ClapTrap:: ClapTrap()
: _name( C_B_HI_P "sane_default" C_RST ) {

	std::cout << clap_trap_str + "	default constructor called" << std::endl;
}

ClapTrap:: ClapTrap( std::string const &name )
: _name( C_B_HI_P + name + C_RST ) {

	std::cout << clap_trap_str + "	string constructor called" << std::endl;
}

ClapTrap:: ClapTrap( ClapTrap const &src )
: _name( C_B_HI_P + src._name + C_RST ), _ad( CLAPTRAP_AD ) {

	std::cout << clap_trap_str + "	copy constructor called" << std::endl;
	_hp = ( src._hp > CLAPTRAP_HP ? CLAPTRAP_HP : src._hp );
	_ep = ( src._ep > CLAPTRAP_EP ? CLAPTRAP_EP : src._ep );
}

// ------------------------------------------------------------------ destructor

ClapTrap:: ~ClapTrap() {

	std::cout << clap_trap_str + "	destructor called" << std::endl;
}

// --------------------------------------------------- member operator overloads

ClapTrap &ClapTrap:: operator = ( ClapTrap const &src ) {

	std::cout << clap_trap_str + "	assignment operator called" << std::endl;
	if ( this != &src ) {
		_name = src._name;
		_hp = ( src._hp > CLAPTRAP_HP ? CLAPTRAP_HP : src._hp );
		_ep = ( src._ep > CLAPTRAP_EP ? CLAPTRAP_EP : src._ep );
		_ad = CLAPTRAP_AD;
	}
	return *this;
}
