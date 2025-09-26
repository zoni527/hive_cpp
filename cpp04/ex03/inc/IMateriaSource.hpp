/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:50:26 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:14:18 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource {

public:
	virtual	~IMateriaSource() {}
// -----------------------------------------------------------------------------
	virtual void		learnMateria( AMateria* ) = 0;
	virtual AMateria*	createMateria( std::string const &type ) = 0;
};

#endif
