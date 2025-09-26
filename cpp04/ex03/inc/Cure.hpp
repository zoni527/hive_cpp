/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:57:59 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:14:20 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {

public:
// -----------------------------------------------------------------------------
	Cure	*clone() const override;
	void	use( ICharacter &target ) override;
// -----------------------------------------------------------------------------
	Cure();
	Cure( Cure const &src ) = delete;
// -----------------------------------------------------------------------------
	~Cure();
// -----------------------------------------------------------------------------
	Cure &operator = ( Cure const &src ) = delete;
};

#endif
