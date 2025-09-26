/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:13:57 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/09 10:43:02 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm() = delete;
	RobotomyRequestForm( RobotomyRequestForm const &other ) = delete;
	RobotomyRequestForm( std::string const &target );
	~RobotomyRequestForm() = default;

	RobotomyRequestForm	&operator=( RobotomyRequestForm const &rhs ) = delete;

	virtual void	execute( Bureaucrat const &executor ) const override;

private:
	static constexpr char const		*NAME		= "robotomy request";
	static constexpr unsigned int	SIGN_GRADE	= 72;
	static constexpr unsigned int	EXEC_GRADE	= 45;
};

using RoboForm = RobotomyRequestForm;
