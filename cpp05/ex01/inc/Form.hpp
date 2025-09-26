/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:05:56 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/08 14:14:08 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
public:
	Form();
	Form( Form const &other );
	Form(	std::string const &name,
			unsigned int gradeToSign,
			unsigned int gradeToExec,
			bool isSigned = false );
	~Form() = default;

	Form	&operator=( Form const &rhs ) = delete;

	std::string const	&getName() const;
	unsigned int		getGradeToSign() const;
	unsigned int		getGradeToExec() const;
	bool				getIsSigned() const;

	void				beSigned( Bureaucrat const &b );

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

private:
	std::string const	_name;
	unsigned int const	_gradeToSign;
	unsigned int const	_gradeToExec;
	bool				_isSigned = false;
};

std::ostream	&operator<<( std::ostream &os, Form const &f );
