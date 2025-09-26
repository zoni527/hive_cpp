/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:31:12 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/09 16:00:00 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ansi_colors.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
	: _name( Bureaucrat::DEFAULT_NAME ),
	_grade( Bureaucrat::DEFAULT_GRADE ) {}

Bureaucrat::Bureaucrat( std::string const &name, unsigned int grade )
	: _name( name ), _grade( grade )
{
	if ( _grade > 150 )
		throw GradeTooLowException();
	else if ( _grade < 1 )
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat( Bureaucrat const &other )
	: _name( other._name ), _grade( other._grade ) {}

/* -------------------------------------------------------------------------- */

std::string const	&Bureaucrat:: getName() const
{
	return _name;
}

unsigned int		Bureaucrat:: getGrade() const
{
	return _grade;
}

void				Bureaucrat:: incrementGrade()
{
	if ( _grade == 1 )
		throw GradeTooHighException();
	--_grade;
}

void				Bureaucrat:: decrementGrade()
{
	if ( _grade == 150 )
		throw GradeTooLowException();
	++_grade;
}

void				Bureaucrat:: signForm( AForm &f ) const
{
	try
	{
		f.beSigned( *this );
		std::cout	<< C_B_G "[X] " << C_RST << _name << " signed "
					<< f.getName() << " form" << std::endl;
	}
	catch( std::exception &e )
	{
		std::cout
			<< C_B_R "[ ] " << C_RST << _name << " couldn't sign "
			<< f.getName() << " form because: "
			<< C_HI_R << _name << "'s grade is " << getGrade()
			<< ", the grade required to sign " << f.getName()
			<< " form is " << f.getGradeToSign() << "." << C_RST << std::endl;
	}
}

void				Bureaucrat:: executeForm( AForm const &f ) const
{
	try
	{
		f.execute( *this );
		std::cout	<< C_B_G "[X] " << C_RST << _name << " executed "
					<< f.getName() << " form" << std::endl;
	}
	catch( std::exception &e )
	{
		std::cout	<< C_B_R "[ ] " << C_RST << _name << " couldn't execute "
					<< f.getName() << "form because: "
					<< C_HI_R << e.what() << C_RST << std::endl;
	}
}

/* -------------------------------------------------------------------------- */

std::ostream	&operator<<( std::ostream &os, Bureaucrat const &b )
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return os;
}

/* -------------------------------------------------------------------------- */

const char	*Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Bureaucrat's grade is too low";
}

const char	*Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Bureaucrat's grade is too high";
}
