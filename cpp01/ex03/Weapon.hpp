/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:23:02 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/02 16:09:14 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon {

public:
	std::string const	&getType() const;
	void				setType( std::string const &str );

	Weapon( std::string const &str );
	~Weapon();

private:
	std::string	_type;
};
