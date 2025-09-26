/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:05:39 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/11 11:32:05 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

public:
// ------------------------------------------------------------ member functions
	void	attack( std::string const &target );
	void	whoAmI();
// ---------------------------------------------------------------- constructors
	DiamondTrap();
	DiamondTrap( std::string const &name );
	DiamondTrap( DiamondTrap const &src );
// ------------------------------------------------------------------ destructor
	~DiamondTrap();
// --------------------------------------------------- member operator overloads
	DiamondTrap &operator = ( DiamondTrap const &src );

private:
	std::string	_name;
};

#endif
