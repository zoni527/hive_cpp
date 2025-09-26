/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:59:37 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:15:21 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:
// ------------------------------------------------------------ member functions
	void	makeSound() const;
// ---------------------------------------------------------------- constructors
	WrongCat();
	WrongCat( WrongCat const &src );
// ------------------------------------------------------------------ destructor
	~WrongCat();
// --------------------------------------------------- member operator overloads
	WrongCat	&operator = ( WrongCat const &src );
};

#endif
