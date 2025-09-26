/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:05:56 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/09 15:48:43 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
public:
	AForm() = delete;
	AForm( AForm const &other );
	AForm(	std::string const &name,
			std::string const &target,
			unsigned int gradeToSign,
			unsigned int gradeToExec,
			bool isSigned = false );
	virtual ~AForm() = default;

	AForm	&operator=( AForm const &rhs ) = delete;

	std::string const	&getName() const;
	std::string const	&getTarget() const;
	unsigned int		getGradeToSign() const;
	unsigned int		getGradeToExec() const;
	bool				getIsSigned() const;

	void				beSigned( Bureaucrat const &signer );
	virtual void		execute( Bureaucrat const &executor ) const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		const char	*what() const noexcept override;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char	*what() const noexcept override;
	};

	class FormNotSignedException : public std::exception
	{
	public:
		const char	*what() const noexcept override;
	};

private:
	std::string const	_name;
	std::string const	_target;
	unsigned int const	_gradeToSign;
	unsigned int const	_gradeToExec;
	bool				_isSigned = false;
};

std::ostream	&operator<<( std::ostream &os, AForm const &f );
