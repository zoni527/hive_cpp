/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:08:24 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:13:50 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class AAnimal {

public:
// ------------------------------------------------------------ member functions
	virtual void	makeSound() const = 0;
	std::string		getType() const;
// ---------------------------------------------------------------- constructors
	AAnimal();
	AAnimal( AAnimal const &src );
// ------------------------------------------------------------------ destructor
	virtual	~AAnimal();
// --------------------------------------------------- member operator overloads
	AAnimal &operator = ( AAnimal const &src );

protected:
	std::string	_type;
};

#endif
