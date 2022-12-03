/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:01:03 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/02 15:30:53 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "ft_containers.hpp"
#include "vector.hpp"

START

template< class T, class Container = ft::vector< T > >
class stack {

protected:

	Container	c;

public:

	typedef				Container container_type;
	typedef typename	Container::value_type value_type;
	typedef typename	Container::size_type size_type;
	typedef typename	Container::reference reference;

/* ~~~~~ CANONICAL FORM ~~~~~ */

	explicit stack( const container_type &a = container_type() )
		: c(a) {}

	stack
	&operator=( const stack &rhs ) {

		if (this == &rhs) 
			return (*this);
		this->c = rhs.c;

		return (*this);
	}
	
	stack( const stack &src ) {

		*this = src;
	}


	~stack( void ) {}

	size_type
	size( void ) const {

		return (this->c.size());
	}

	bool
	empty( void ) const {

		return (this->c.empty());
	}

	value_type
	&top( void ) {

		return (this->c.back());
	}

	const value_type
	&top( void ) const {

		return (this->c.back());
	}
	
	void
	push( const value_type &n ) {

		this->c.push_back(n);
	}

	void
	pop( void ) {

		return (this->c.pop_back());
	}

	friend bool
	operator==( const ft::stack< T, Container > &lhs, const ft::stack< T, Container > &rhs ) {

		return (lhs.c == rhs.c);
	}

	friend bool
	operator!=( const ft::stack< T, Container > &lhs, const ft::stack< T, Container > &rhs ) {

		return (lhs.c != rhs.c);
	}

	friend bool
	operator<( const ft::stack< T, Container > &lhs, const ft::stack< T, Container > &rhs ) {
		
		return (lhs.c < rhs.c);
	}

	friend bool
	operator<=( const ft::stack< T, Container > &lhs, const ft::stack< T, Container > &rhs ) {
		
		return (lhs.c <= rhs.c);
	}

	friend bool
	operator>( const ft::stack< T, Container > &lhs, const ft::stack< T, Container > &rhs ) {
		
		return (lhs.c > rhs.c);
	}

	friend bool
	operator>=( const ft::stack< T, Container > &lhs, const ft::stack< T, Container > &rhs ) {
		
		return (lhs.c >= rhs.c);
	}

	void
	swap( stack< T, Container > &lhs, stack< T, Container > &rhs) {

		lhs.swap(rhs);
	}

};

STOP

#endif 