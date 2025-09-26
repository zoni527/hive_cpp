/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:41:04 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/09 15:50:36 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm:: AForm( AForm const &other )
	:	_name( other._name ),
		_target( other._target ),
		_gradeToSign( other._gradeToSign ),
		_gradeToExec( other._gradeToExec ),
		_isSigned( other._isSigned ) {}

AForm:: AForm(	std::string const &name,
				std::string const &target,
				unsigned int gradeToSign,
				unsigned int gradeToExec,
				bool isSigned )
	:	_name( name ),
		_target( target ),
		_gradeToSign( gradeToSign ),
		_gradeToExec( gradeToExec ),
		_isSigned( isSigned )
{
	if ( _gradeToSign > 150 || _gradeToExec > 150 )
		throw GradeTooLowException();
	else if ( _gradeToSign < 1 || _gradeToExec < 1 )
		throw GradeTooHighException();
}

/* -------------------------------------------------------------------------- */

std::string const	&AForm:: getName() const
{
	return _name;
}

std::string const	&AForm:: getTarget() const
{
	return _target;
}

unsigned int		AForm:: getGradeToSign() const
{
	return _gradeToSign;
}

unsigned int		AForm:: getGradeToExec() const
{
	return _gradeToExec;
}

bool				AForm:: getIsSigned() const
{
	return _isSigned;
}

void				AForm:: beSigned( Bureaucrat const &signer )
{
	if ( signer.getGrade() > _gradeToSign )
		throw GradeTooLowException();
	_isSigned = true;
}

/* -------------------------------------------------------------------------- */

std::ostream	&operator<<( std::ostream &os, AForm const &f )
{
	os	<< "Name:			" << f.getName() << "\n"
		<< "Target:			" << f.getTarget() << "\n"
		<< "Grade to sign:		" << f.getGradeToSign() << "\n"
		<< "Grade to execute:	" << f.getGradeToExec() << std::endl;
	return os;
}

/* -------------------------------------------------------------------------- */

const char	*AForm::GradeTooLowException::what() const noexcept
{
	return "Form's grade is too low";
}

const char	*AForm::GradeTooHighException::what() const noexcept
{
	return "Form's grade is too high";
}

const char	*AForm::FormNotSignedException::what() const noexcept
{
	return "Form is not signed";
}
