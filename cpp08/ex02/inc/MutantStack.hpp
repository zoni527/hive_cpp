/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:44:20 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/22 23:03:43 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template<class T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() = default;
	MutantStack( MutantStack const &other );
	~MutantStack() = default;

	MutantStack	&operator=( MutantStack const &rhs );

	using cont = typename std::stack<T>::container_type;

	using iterator					= typename cont::iterator;
	using const_iterator			= typename cont::const_iterator;
	using reverse_iterator			= typename cont::reverse_iterator;
	using const_reverse_iterator	= typename cont::const_reverse_iterator;

	iterator				begin();
	iterator				end();
	const_iterator			begin()		const;
	const_iterator			end()		const;

	reverse_iterator		rbegin();
	reverse_iterator		rend();
	const_reverse_iterator	rbegin()	const;
	const_reverse_iterator	rend()		const;

	const_iterator			cbegin()	const;
	const_iterator			cend()		const;
	const_reverse_iterator	crbegin()	const;
	const_reverse_iterator	crend()		const;
};

template<class T>
MutantStack<T>:: MutantStack( MutantStack<T> const &other )
	: std::stack<T>( other ) {}

template<class T>
MutantStack<T>	&MutantStack<T>:: operator=( MutantStack<T> const &rhs )
{
	if ( this != &rhs )
		std::stack<T>::operator=( rhs );
	
	return *this;
}

template<class T>
typename MutantStack<T>::iterator	MutantStack<T>:: begin()
{
	return this->c.begin();
}

template<class T>
typename MutantStack<T>::iterator	MutantStack<T>:: end()
{
	return this->c.end();
}

template<class T>
typename MutantStack<T>::const_iterator	MutantStack<T>:: begin() const
{
	return this->c.begin();
}

template<class T>
typename MutantStack<T>::const_iterator	MutantStack<T>:: end() const
{
	return this->c.end();
}

template<class T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>:: rbegin()
{
	return this->c.rbegin();
}

template<class T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>:: rend()
{
	return this->c.rend();
}

template<class T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>:: rbegin() const
{
	return this->c.rbegin();
}

template<class T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>:: rend() const
{
	return this->c.rend();
}

template<class T>
typename MutantStack<T>::const_iterator	MutantStack<T>:: cbegin() const
{
	return this->c.cbegin();
}

template<class T>
typename MutantStack<T>::const_iterator	MutantStack<T>:: cend() const
{
	return this->c.cend();
}

template<class T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>:: crbegin() const
{
	return this->c.crbegin();
}

template<class T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>:: crend() const
{
	return this->c.crend();
}
