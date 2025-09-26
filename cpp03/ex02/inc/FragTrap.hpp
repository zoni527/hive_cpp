/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:05:55 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/10 13:09:28 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define FRAGTRAP_HP	100
# define FRAGTRAP_EP	100
# define FRAGTRAP_AD	50

class FragTrap : public ClapTrap {

public:
// ------------------------------------------------------------ member functions
	void	attack( std::string const &target );
	void	highFivesGuys();
// ---------------------------------------------------------------- constructors
	FragTrap();
	FragTrap( std::string const &name );
	FragTrap( FragTrap const &src );
// ------------------------------------------------------------------ destructor
	~FragTrap();
// --------------------------------------------------- member operator overloads
	FragTrap &operator = ( FragTrap const &src );
};

#endif
