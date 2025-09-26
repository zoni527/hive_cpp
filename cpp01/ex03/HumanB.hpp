/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:49:52 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/02 16:08:20 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB {

public:
	void	attack();
	void	setWeapon( Weapon const &weapon );

	HumanB( std::string const &str );
	~HumanB();

private:
	std::string const	_name;
	Weapon const		*_weapon = nullptr;
};
