/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:50:42 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/10 12:57:28 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern
{
public:
	Intern() = default;
	Intern( Intern const &other ) = default;
	~Intern() = default;

	Intern	&operator=( Intern const &rhs ) = default;

	AForm	*makeForm( std::string const &formName, std::string const &target ) const;
};
