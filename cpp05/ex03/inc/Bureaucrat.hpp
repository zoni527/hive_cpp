/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:24:44 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/09 15:50:28 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat( Bureaucrat const &other );
	Bureaucrat( std::string const &_name, unsigned int grade );
	~Bureaucrat() = default;

	Bureaucrat	&operator=( Bureaucrat const &other ) = delete;

	std::string const	&getName() const;
	unsigned int		getGrade() const;

	void				incrementGrade();
	void				decrementGrade();

	void				signForm( AForm &f ) const;
	void				executeForm( AForm const &f ) const;

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
	unsigned int		_grade;

	static constexpr char const		*DEFAULT_NAME	= "Default Dave";
	static constexpr unsigned int	DEFAULT_GRADE	= 150;
};

std::ostream	&operator<<( std::ostream &os, Bureaucrat const &b );
