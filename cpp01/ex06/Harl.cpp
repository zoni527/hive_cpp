/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:16:50 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/02 16:09:43 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

std::string const levels[] = {
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR",
};

void Harl:: complain( std::string level ) {

	static void (Harl:: *functions[])() {
		&Harl:: debug,
		&Harl:: info,
		&Harl:: warning,
		&Harl:: error,
		nullptr
	};

	int level_index;
	for (level_index = 0; level_index < 4; ++level_index)
		if (levels[level_index] == level)
			break;

	void (Harl:: *f)();
	f = functions[level_index];
	if (f)
		(this->*f)();
	else
		std::cout << "Incoherent mumbling noises" << std::endl;
}

void Harl:: debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-"
		"pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl:: info() {
	std::cout << "I cannot believe adding extra bacon costs more money.\n"
		"You didn’t put enough bacon in my burger!\n"
		"If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl:: warning() {
	std::cout << "I think I deserve to have some extra bacon for free.\n"
		"I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl:: error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
