/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:31:12 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/03 15:57:26 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

/* -------------------------------------------------------------------------- */

const char	*Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Bureaucrat's grade is too low";
}

const char	*Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Bureaucrat's grade is too high";
}

/* -------------------------------------------------------------------------- */

std::ostream	&operator<<( std::ostream &os, Bureaucrat const &b )
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return os;
}

