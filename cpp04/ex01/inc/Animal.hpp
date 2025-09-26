/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:08:24 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:15:14 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {

public:
// ------------------------------------------------------------ member functions
	virtual void	makeSound() const;

	std::string		getType() const;
// ---------------------------------------------------------------- constructors
	Animal();
	Animal( Animal const &src );
// ------------------------------------------------------------------ destructor
	virtual	~Animal();
// --------------------------------------------------- member operator overloads
	Animal &operator = ( Animal const &src );

protected:
	std::string	_type;
};

#endif
