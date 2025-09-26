/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:01:22 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/09 15:53:38 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

std::string const	SHRUB =
R"(
      o
     / \
    o   o
   / \   \
  o   o   o
 / \     / \
o   o   o   o
   /   /
  o   o
       \
        o
       /
      o
)";

ShrubForm:: ShrubberyCreationForm( std::string const &target )
	: AForm(	ShrubForm::NAME,
				target,
				ShrubForm::SIGN_GRADE,
				ShrubForm::EXEC_GRADE ) {}

void	ShrubberyCreationForm:: execute( Bureaucrat const &executor ) const
{
	if ( !getIsSigned() )
		throw FormNotSignedException();
	if ( executor.getGrade() > getGradeToExec() )
		throw Bureaucrat::GradeTooLowException();
	std::ofstream	output( getTarget() + "_shrubbery" );
	if ( !output )
		throw std::runtime_error( "ERROR: Couldn't open file for shrubbery writing" );
	output << SHRUB;
}
