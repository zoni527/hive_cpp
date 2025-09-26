/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:31:36 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/02 16:08:56 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA {

public:
	void	attack();

	HumanA( std::string const &str, Weapon const &weapon);
	~HumanA();

private:
	std::string	const	_name;
	Weapon const		&_weapon;
};
