/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:40:20 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/02 16:08:37 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name ) {

	Zombie *horde;
	horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
		horde[i].set_name(name + " " + std::to_string(i + 1));
	return horde;
}
