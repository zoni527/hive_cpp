/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:22:22 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/09 15:57:03 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <chrono>

RoboForm:: RobotomyRequestForm( std::string const &target )
	: AForm(	RoboForm::NAME,
				target,
				RoboForm::SIGN_GRADE,
				RoboForm::EXEC_GRADE ) {}

void	RoboForm:: execute( Bureaucrat const &executor ) const
{
	if ( !getIsSigned() )
		throw FormNotSignedException();
	if ( executor.getGrade() > getGradeToExec() )
		throw Bureaucrat::GradeTooLowException();
	std::cout << "* DRRRRRNGGG PSHHH CLANG CLANG BZZZ WWHOOOOWWWZ *\n";
	if ( std::rand() % 2 == 0 )
	{
		std::cout	<< getTarget()
					<< " has been succesfully Robotomized." << std::endl;
	}
	else
	{
		std::cout	<< "The robotomy failed, " << getTarget()
					<< " has died. Bummer." << std::endl;
	}
}
