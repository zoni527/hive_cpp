/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:53:01 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:15:23 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {

public:
// ------------------------------------------------------------ member functions
	void		makeSound() const;
	std::string	getType() const;
// ---------------------------------------------------------------- constructors
	WrongAnimal();
	WrongAnimal( WrongAnimal const &src );
// ------------------------------------------------------------------ destructor
	virtual	~WrongAnimal();
// --------------------------------------------------- member operator overloads
	WrongAnimal	&operator = ( WrongAnimal const &src );

protected:
	std::string	_type;
};

#endif
