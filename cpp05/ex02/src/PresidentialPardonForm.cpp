/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:28:45 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/09 15:57:30 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PrezForm:: PresidentialPardonForm( std::string const &target )
	: AForm(	PrezForm::NAME,
				target,
				PrezForm::SIGN_GRADE,
				PrezForm::EXEC_GRADE ) {}

void	PrezForm:: execute( Bureaucrat const &executor ) const
{
	if ( !getIsSigned() )
		throw FormNotSignedException();
	if ( executor.getGrade() > getGradeToExec() )
		throw Bureaucrat::GradeTooLowException();
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
