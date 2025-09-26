/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:33:05 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/02 16:08:43 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie {

public:
	void	announce();

	Zombie ();
	Zombie ( std::string const &name );
	~Zombie();
	void	set_name( std::string const &name );

private:
	std::string	_name;
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );
Zombie	*zombieHorde( int N, std::string name );
