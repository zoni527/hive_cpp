/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:41:04 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/08 14:27:30 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form:: Form()
	: _name( "Generic form"), _gradeToSign( 150 ), _gradeToExec( 150 ) {}

Form:: Form( Form const &other )
	:	_name( other._name ),
		_gradeToSign( other._gradeToSign ),
		_gradeToExec( other._gradeToExec ),
		_isSigned( other._isSigned ) {}

Form:: Form(	std::string const &name,
				unsigned int gradeToSign,
				unsigned int gradeToExec,
				bool isSigned )
	:	_name( name ),
		_gradeToSign( gradeToSign ),
		_gradeToExec ( gradeToExec ),
		_isSigned( isSigned )
{
	if ( _gradeToSign > 150 || _gradeToExec > 150 )
		throw GradeTooLowException();
	else if ( _gradeToSign < 1 || _gradeToExec < 1 )
		throw GradeTooHighException();
}

/* -------------------------------------------------------------------------- */

std::string const	&Form:: getName() const
{
	return _name;
}

unsigned int		Form:: getGradeToSign() const
{
	return _gradeToSign;
}

unsigned int		Form:: getGradeToExec() const
{
	return _gradeToExec;
}

bool				Form:: getIsSigned() const
{
	return _isSigned;
}

void				Form:: beSigned( Bureaucrat const &b )
{
	if ( b.getGrade() > _gradeToSign )
		throw GradeTooLowException();
	_isSigned = true;
}

/* -------------------------------------------------------------------------- */

std::ostream	&operator<<( std::ostream &os, Form const &f )
{
	os	<< f.getName() << ", grade required to sign: " << f.getGradeToSign()
		<< ", grade required to execute: " << f.getGradeToExec()
		<< "." << std::endl;
	return os;
}

/* -------------------------------------------------------------------------- */

const char	*Form::GradeTooLowException::what() const noexcept
{
	return "Form's grade is too low";
}

const char	*Form::GradeTooHighException::what() const noexcept
{
	return "Form's grade is too high";
}
