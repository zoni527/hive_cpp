/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:06:15 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/09 10:42:49 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm() = delete;
	ShrubberyCreationForm( ShrubberyCreationForm const &other ) = delete;
	ShrubberyCreationForm( std::string const &target );
	~ShrubberyCreationForm() = default;

	ShrubberyCreationForm	&operator=( ShrubberyCreationForm const &rhs ) = delete;

	virtual void	execute( Bureaucrat const &executor ) const override;

private:
	static constexpr char const		*NAME		= "shrubbery creation";
	static constexpr unsigned int	SIGN_GRADE	= 145;
	static constexpr unsigned int	EXEC_GRADE 	= 137;
};

using ShrubForm = ShrubberyCreationForm;
