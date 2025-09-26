/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:47:29 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/27 11:15:11 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

public:
// ------------------------------------------------------------ member functions
	void		makeSound() const override;
	std::string	get_idea( size_t index );
	std::string	get_random_idea();
// ---------------------------------------------------------------- constructors
	Dog();
	Dog( Dog const &src );
// ------------------------------------------------------------------ destructor
	~Dog();
// --------------------------------------------------- member operator overloads
	Dog &operator = ( Dog const &src );

private:
	Brain	*_brain = nullptr;
};

#endif
