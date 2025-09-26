/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:27:29 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/09 10:43:19 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm() = delete;
	PresidentialPardonForm( PresidentialPardonForm const &other ) = delete;
	PresidentialPardonForm( std::string const &target );
	~PresidentialPardonForm() = default;

	PresidentialPardonForm	&operator=( PresidentialPardonForm const &rhs ) = delete;

	virtual void	execute( Bureaucrat const &executor ) const override;

private:
	static constexpr char const		*NAME		= "presidential pardon";
	static constexpr unsigned int	SIGN_GRADE	= 25;
	static constexpr unsigned int	EXEC_GRADE	= 5;
};

using PrezForm = PresidentialPardonForm;
