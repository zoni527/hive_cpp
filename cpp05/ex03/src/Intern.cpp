/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:58:15 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/10 13:51:06 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

enum FormType : int
{
	SHRUB,
	ROBO,
	PREZ,
	UNKNOWN,
};

constexpr char const * const	formNames[] =
{
	"shrubbery creation", "robotomy request", "presidential pardon"
};

AForm	*Intern:: makeForm( std::string const &formName, std::string const &target ) const
{
	FormType	type = UNKNOWN;
	for ( size_t i = 0; i < sizeof( formNames ) / sizeof( formNames[0] ); ++i )
	{
		if ( formNames[i] == formName )
		{
			type = static_cast<FormType>(i);
			std::cout << "(unpaid) intern creates " << formName << " form" << std::endl;
			break;
		}
	}
	switch( type )
	{
		case SHRUB:
			return new ShrubberyCreationForm( target );
		case ROBO:
			return new RobotomyRequestForm( target );
		case PREZ:
			return new PresidentialPardonForm( target );
		default:
			std::string	msg = formName + " form is not known to the (unpaid) intern";
			std::cout << msg << std::endl;
			throw std::invalid_argument( msg );
	}
}
